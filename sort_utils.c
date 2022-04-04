/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:08:28 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/02 12:25:28 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *fisrt, int size)
{
	t_list	*t;
	int		i;
	int		min;

	i = 0;
	t = fisrt;
	min = t->data;
	while (i < size)
	{
		if (t->data < min)
			min = t->data;
		i++;
		t = t->next;
	}
	return (min);
}

int	get_max(t_list *fisrt, int size)
{
	t_list	*t;
	int		i;
	int		max;

	i = 0;
	t = fisrt;
	max = t->data;
	while (i < size)
	{
		if (t->data > max)
			max = t->data;
		i++;
		t = t->next;
	}
	return (max);
}

int	ft_indix(t_a_index *ind, int data)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = ind->first_n;
	while (temp->data != data)
		temp = temp->next;
	while (temp->data != ind->first_n->data)
	{
		temp = temp->prev;
		count++;
	}
	return (count);
}

int	ft_indix_b(t_b_index *ind, int data)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = ind->first_n;
	while (temp->data != data)
		temp = temp->next;
	while (temp->data != ind->first_n->data)
	{
		temp = temp->prev;
		count++;
	}
	return (count);
}
