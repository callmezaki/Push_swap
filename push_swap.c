/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 06:36:19 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/02 16:50:33 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_sort(t_a_index	*ind, t_b_index	*ind_b)
{
	t_lis		*lis;

	lis = malloc(sizeof(t_lis));
	if (!lis)
		exit(0);
	if (check_nearly_sroted(ind))
		final_sort(ind);
	else if (ind->size == 3)
		three_sort(ind);
	else if (ind->size == 5)
		five_sort(ind, ind_b);
	else
	{
		get_best(lis, ind, ind->first_n);
		push_intilis(ind, ind_b, lis);
		return_in_place(ind, ind_b);
		free(lis);
	}
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
	if (check_sroted(ind))
		exit(0);
	ft_sort(ind, ind_b);
	free_stacks(ind, ind_b);
	free(args);
	exit(0);
}
