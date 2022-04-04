/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:48:06 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/02 09:57:39 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nearly_sroted(t_a_index *ind)
{
	t_list	*temp;
	int		len;
	int		j;

	len = 0;
	j = 0;
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
		temp = temp->next;
		len++;
	}
	return (0);
}

int	check_sroted(t_a_index *ind)
{
	t_list	*temp;
	int		len;
	int		j;

	len = 0;
	j = 0;
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

void	final_sort(t_a_index *ind)
{
	int	s;

	s = node_to_top(ind, get_min(ind->first_n, ind->size));
	while (ind->first_n->data != get_min(ind->first_n, ind->size))
	{
		if (s > ind->size / 2)
			ft_ra(ind);
		else
			ft_rra(ind);
	}
}

int	node_to_top(t_a_index *ind, int data)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = ind->first_n;
	while (temp->data != data)
		temp = temp->next;
	while (temp->data != ind->first_n->data)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}

int	node_to_top_b(t_b_index *ind_b, int data)
{
	int		count;
	t_list	*temp;

	count = 0;
	temp = ind_b->first_n;
	while (temp->data != data)
		temp = temp->next;
	while (temp->data != ind_b->first_n->data)
	{
		temp = temp->next;
		count++;
	}
	return (count);
}
