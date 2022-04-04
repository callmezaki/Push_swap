/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:02:04 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/02 15:25:57 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_ft(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	compare_move(char *str, t_a_index *ind, t_b_index *ind_b)
{
	if (!ft_strcmp(str, "sa\n"))
		ft_sa(ind);
	else if (!ft_strcmp(str, "sb\n"))
		ft_sb(ind_b);
	else if (!ft_strcmp(str, "ss\n"))
		ft_ss(ind_b, ind);
	else if (!ft_strcmp(str, "ra\n"))
		ft_ra(ind);
	else if (!ft_strcmp(str, "rb\n"))
		ft_rb(ind_b);
	else if (!ft_strcmp(str, "rr\n"))
		ft_rr(ind, ind_b);
	else if (!ft_strcmp(str, "rra\n"))
		ft_rra(ind);
	else if (!ft_strcmp(str, "rrb\n"))
		ft_rrb(ind_b);
	else if (!ft_strcmp(str, "rrr\n"))
		ft_rrr(ind, ind_b);
	else if (!ft_strcmp(str, "pa\n"))
		push_b_to_a(ind, ind_b);
	else if (!ft_strcmp(str, "pb\n"))
		push_a_to_b(ind, ind_b);
	else
		exit_ft();
}

int	check_sroted(t_a_index *ind)
{
	t_list	*temp;
	int		len;
	int		j;

	len = 0;
	temp = ind->first_n;
	while (len < ind->size)
	{
		j = 0;
		while (j < ind->size && temp->data < temp->next->data)
		{
			temp = temp->next;
			j++;
		}
		if (j == ind->size - 1)
			return (1);
		len++;
	}
	return (0);
}

void	read_check(t_a_index *ind, t_b_index *ind_b)
{
	char		*line;

	line = get_next_line(0);
	while (line)
	{
		compare_move(line, ind, ind_b);
		free(line);
		line = get_next_line(0);
	}
	if (check_sroted(ind) && ind_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int ac, char **av)
{
	t_a_index	*ind;
	t_b_index	*ind_b;
	t_args		*args;

	if (ac == 1)
		exit(EXIT_FAILURE);
	ind = NULL;
	ind_b = NULL;
	args = NULL;
	ind = ma_pro_a(ind);
	ind_b = ma_pro_b(ind_b);
	args = ma_pro_args(args);
	init_args(ac, av, args);
	check_isdigit(args->len, args->tab);
	check_int(args->len, args->tab);
	check_duplictes(args->len, args->tab);
	init_list(args->tab, ind, 0);
	init_list_b(ind_b);
	free_tab(args->tab);
	read_check(ind, ind_b);
	free_stacks(ind, ind_b);
	free(args);
	exit(EXIT_SUCCESS);
}
