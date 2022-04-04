/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:19:52 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/02 13:54:23 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	delete_node(t_list *from, t_a_index *ind)
{
	if (from == ind->first_n)
		ind->first_n = from->next;
	if (from == ind->last_n)
		ind->first_n = from->prev;
	if (from == from->next)
		from = NULL;
	else
	{
		if (from == ind->last_n)
		{
			ind->last_n = from->prev;
			ind->first_n = from->next;
		}
		from->prev->next = from->next;
		from->next->prev = from->prev;
		from = from->next;
	}
	ind->size -= 1;
}

void	delete_node_b(t_list *from, t_b_index *ind)
{
	if (from == ind->first_n)
		ind->first_n = from->next;
	if (from == ind->last_n)
		ind->first_n = from->prev;
	if (from == from->next)
		from = NULL;
	else
	{
		if (from == ind->last_n)
			ind->first_n = from->next;
		from->prev->next = from->next;
		from->next->prev = from->prev;
		from = from->next;
	}
	ind->size -= 1;
}

void	push_a_to_b(t_a_index *ind, t_b_index *ind_b)
{
	t_list	*save;
	t_list	*stock;

	if (ind->size == 0)
		return ;
	save = ind->first_n;
	delete_node(ind->first_n, ind);
	if (ind_b->first_n)
	{
		stock = ind_b->first_n->prev;
		ind_b->first_n->prev = save;
		ind_b->first_n->prev->next = ind_b->first_n;
		ind_b->first_n->prev->prev = stock;
		ind_b->first_n->prev->prev->next = save;
		ind_b->first_n = ind_b->first_n->prev;
		ind_b->first_n = ind_b->first_n;
	}
	else
	{
		ind_b->first_n = save;
		ind_b->first_n->next = ind_b->first_n;
		ind_b->first_n->prev = ind_b->first_n;
	}
	ind_b->size += 1;
}

void	push_b_to_a(t_a_index *ind, t_b_index *ind_b)
{
	t_list	*save;
	t_list	*stock;

	if (!ind_b->first_n)
		return ;
	save = ind_b->first_n;
	delete_node_b(ind_b->first_n, ind_b);
	if (ind->first_n)
	{
		stock = ind->first_n->prev;
		ind->first_n->prev = save;
		ind->first_n->prev->next = ind->first_n;
		ind->first_n->prev->prev = stock;
		ind->first_n->prev->prev->next = save;
		ind->first_n = ind->first_n->prev;
	}
	else
	{
		ind->first_n = save;
		ind->first_n->next = ind->first_n;
		ind->first_n->prev = ind->first_n;
	}
	ind->size += 1;
}

void	free_stack(t_a_index *ind)
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
}
