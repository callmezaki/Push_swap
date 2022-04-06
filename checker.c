/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:02:04 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/06 16:09:10 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exit_ft( t_a_index *ind, t_b_index *ind_b)
{
	write(2, "Error\n", 6);
	free_stacks(ind, ind_b);
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
		exit_ft(ind, ind_b);
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
	if (line)
		free(line);
	if (check_sroted(ind) && ind_b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

void	check_args(t_args *args)
{
	int	k;

	k = 0;
	if (!check_isdigit(args->len, args->tab))
		k = 1;
	else if (!check_int(args->len, args->tab))
		k = 1;
	else if (!check_duplictes(args->len, args->tab))
		k = 1;
	if (k == 1)
	{
		free_tab(args->tab);
		free(args);
		exit(0);
	}
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
	args = ma_pro_args(args);
	init_args(ac, av, args);
	check_args(args);
	ind = ma_pro_a(ind);
	ind_b = ma_pro_b(ind_b);
	init_list(args->tab, ind, 0);
	free_tab(args->tab);
	free(args);
	init_list_b(ind_b);
	read_check(ind, ind_b);
	free_stacks(ind, ind_b);
	exit(EXIT_SUCCESS);
}
