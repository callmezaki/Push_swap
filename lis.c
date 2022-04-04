/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:25:14 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/02 16:54:09 by zait-sli         ###   ########.fr       */
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
		else if (temp.len > lis->len)
			*lis = temp;
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
}
