/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:25:14 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/06 14:53:21 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_lis_len(t_a_index *ind, t_list *node, int start, t_lis lis)
{
	int		i;
	int		big;
	t_list	*temp;

	temp = node;
	i = start;
	big = node->data;
	lis.len = 0;
	lis.len++;
	temp = temp->next;
	if (start == ind->size)
	{
		temp = ind->first_n;
		i = 0;
	}
	while (i < ind->size)
	{
		if (big < temp->data)
			lis.len++;
		if (big < temp->data)
			big = temp->data;
		temp = temp->next;
		i++;
	}
	return (lis.len);
}

t_lis	get_lis(t_a_index *ind, t_list *node, int start, t_lis lis)
{
	int		i;
	int		big;
	t_list	*temp;

	temp = node;
	i = start - 1;
	big = node->data;
	lis.len = 0;
	lis.order = ma_pro_arr(lis.order, get_lis_len(ind, node, start, lis));
	lis.order[lis.len++] = temp->data;
	temp = temp->next;
	if (start == ind->size)
	{
		temp = ind->first_n;
		i = 0;
	}
	while (++i < ind->size)
	{
		if (big < temp->data)
			lis.order[lis.len++] = temp->data;
		if (big < temp->data)
			big = temp->data;
		temp = temp->next;
	}
	return (lis);
}

int	get_best_len(t_lis *lis, t_a_index *ind, t_list *node)
{
	t_lis	temp;
	int		start;
	int		best;

	start = 0;
	while (start < ind->size)
	{
		temp = get_lis(ind, node, start,*lis);
		if (start == 0)
			best = temp.len;
		else if (temp.len > lis->len)
			best = temp.len;
		free(temp.order);
		start++;
		node = node->next;
	}
	return (best);
}

void	get_best(t_lis *lis, t_a_index *ind, t_list *node)
{
	t_lis	temp;
	int		start;

	start = 0;
	while (start < ind->size)
	{
		temp = get_lis(ind, node, start,*lis);
		if (start == 0)
			*lis = temp;
		else if (temp.len != get_best_len(lis, ind, node))
		{
			*lis = temp;
			return ;
		}
		free(temp.order);
		start++;
		node = node->next;
	}
}

int	check_lis(t_list *tt, t_lis *lis)
{
	int	i;

	i = 0;
	while (i < lis->len)
	{
		if (tt->data == lis->order[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}
