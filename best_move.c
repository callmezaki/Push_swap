/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 10:03:13 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/02 12:16:41 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_over_min_max(t_list	*temp
	, t_a_index *ind, t_list *wanted, t_moves *mv)
{
	if (get_min(temp, ind->size) > wanted->data)
	{
		while (temp->data != get_min(temp, ind->size))
			temp = temp->next;
		if (ft_indix(ind, temp->data) > ind->size / 2)
			mv->rra = ind->size - ft_indix(ind, temp->data);
		else
			mv->ra = ft_indix(ind, temp->data);
	}
	else if (get_max(temp, ind->size) < wanted->data)
	{
		while (temp->prev->data != get_max(temp, ind->size))
			temp = temp->next;
		if (ft_indix(ind, temp->data) > ind->size / 2)
			mv->rra = ind->size - ft_indix(ind, temp->data);
		else
			mv->ra = ft_indix(ind, temp->data);
	}
}

void	count_moves(t_a_index *ind, t_list *wanted, t_moves *mv)
{
	t_list	*temp;

	temp = ind->first_n;
	mv->ra = 0;
	mv->rra = 0;
	if (get_min(temp, ind->size) > wanted->data
		|| get_max(temp, ind->size) < wanted->data)
	{
		handle_over_min_max(temp, ind, wanted, mv);
	}
	else
	{
		while (1)
		{
			if (temp->data > wanted->data && temp->prev->data < wanted->data)
			{
				if (ft_indix(ind, temp->data) > ind->size / 2)
					mv->rra = ind->size - ft_indix(ind, temp->data);
				else
					mv->ra = ft_indix(ind, temp->data);
				break ;
			}
			temp = temp->next;
		}
	}
}

int	ft_count(int a, int b, int count)
{
	while (a)
	{
		a--;
		count++;
	}
	while (b)
	{
		b--;
		count++;
	}
	return (count);
}

int	calculate_a(t_moves *mv)
{
	int		count;
	t_moves	temp_mv;

	count = 0;
	temp_mv = *mv;
	while (temp_mv.ra && temp_mv.rb)
	{
		temp_mv.ra--;
		temp_mv.rb--;
	}
	while (temp_mv.rra && temp_mv.rrb)
	{
		temp_mv.rra--;
		temp_mv.rrb--;
	}
	count = ft_count(temp_mv.ra, temp_mv.rra, count);
	return (count);
}

int	calculate_b(t_moves *mv)
{
	int		count;
	t_moves	temp_mv;

	count = 0;
	temp_mv = *mv;
	while (temp_mv.ra && temp_mv.rb)
	{
		temp_mv.ra--;
		temp_mv.rb--;
		count++;
	}
	while (temp_mv.rra && temp_mv.rrb)
	{
		temp_mv.rra--;
		temp_mv.rrb--;
		count++;
	}
	count = ft_count(temp_mv.rb, temp_mv.rrb, count);
	return (count);
}
