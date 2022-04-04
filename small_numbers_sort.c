/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_numbers_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 09:30:01 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/02 09:57:02 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	three_sort(t_a_index *ind)
{
	t_list	*first;

	first = ind->first_n;
	if (first->data < first->prev->data && first->data > first->next->data)
		ft_sa(ind);
	else if (first->data > first->prev->data
		&& first->data > first->next->data
		&& first->next->data > first->prev->data)
	{
		ft_sa(ind);
		ft_rra(ind);
	}
	else if (first->data > first->prev->data
		&& first->data > first->next->data
		&& first->next->data < first->prev->data)
		ft_ra(ind);
	else if (first->data < first->prev->data
		&& first->data < first->next->data
		&& first->next->data > first->prev->data)
	{
		ft_sa(ind);
		ft_ra(ind);
	}
	else if (first->data > first->prev->data && first->data < first->next->data)
		ft_rra(ind);
}

void	five_sort(t_a_index *ind, t_b_index *ind_b)
{
	int	i;
	int	min;
	int	indix;

	i = 0;
	while (i < 2)
	{
		min = get_min(ind->first_n, ind->size);
		indix = ft_indix(ind, min);
		while (ind->first_n->data != min)
		{
			if (indix >= 3)
				ft_rra(ind);
			else
				ft_ra(ind);
		}
		push_a_to_b(ind, ind_b);
		i++;
	}
	three_sort(ind);
	push_b_to_a(ind, ind_b);
	push_b_to_a(ind, ind_b);
	exit(EXIT_SUCCESS);
}
