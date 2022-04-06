/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 06:36:19 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/06 16:08:57 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_intilis(t_a_index *ind, t_b_index *ind_b, t_lis *lis)
{
	int		i;
	int		len;

	i = 0;
	len = ind->size;
	while (i < len && ind->size > lis->len)
	{
		if (!check_lis(ind->first_n, lis))
			push_a_to_b(ind, ind_b);
		else
			ft_ra(ind);
		i++;
	}
	free(lis->order);
}

void	free_stacks(t_a_index *ind, t_b_index *ind_b)
{
	t_list		*t;

	while (ind->size)
	{
		t = ind->first_n;
		ind->first_n = ind->first_n->next;
		free(t);
		ind->size--;
	}
	free(ind);
	free(ind_b);
}

void	ft_sort(t_a_index	*ind, t_b_index	*ind_b)
{
	t_lis		*lis;

	if (check_nearly_sroted(ind))
		final_sort(ind);
	else if (ind->size == 3)
		three_sort(ind);
	else if (ind->size == 5)
		five_sort(ind, ind_b);
	else
	{
		lis = malloc(sizeof(t_lis));
		if (!lis)
		{
			free_stacks(ind, ind_b);
			exit(0);
		}
		get_best(lis, ind, ind->first_n);
		push_intilis(ind, ind_b, lis);
		return_in_place(ind, ind_b);
		final_sort(ind);
		free(lis);
	}
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

	if (ac < 2)
		exit(0);
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
	ft_sort(ind, ind_b);
	free_stacks(ind, ind_b);
	exit(EXIT_SUCCESS);
}
