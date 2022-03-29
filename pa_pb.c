/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:19:52 by zait-sli          #+#    #+#             */
/*   Updated: 2022/03/25 03:34:36 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void delete_node(list *from,a_index *ind)
{
	if (from == ind->first_n)
		ind->first_n = from->next;
	if (from == ind->last_n)
		ind->first_n = from->prev;
	if (from == from->next) {
		from = NULL;
	} 
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
		// free(from);
	}
	ind->size -= 1;
}
void delete_node_b(list *from,b_index *ind)
{
	if (from == ind->first_n)
		ind->first_n = from->next;
	if (from == ind->last_n)
		ind->first_n = from->prev;
	if (from == from->next) {
		from = NULL;
	} 
	else
	{
		if (from == ind->last_n)
			ind->first_n = from->next;
		from->prev->next = from->next;
		from->next->prev = from->prev;
		from = from->next;
		// free(from);
	}
	ind->size -= 1;
}

void push_a_to_b(a_index *ind, b_index *ind_b)
{
	list *save;
	list *stock;
	list *node;

	if (!ind->first_n)
		return;
	if (ind->size == 0)
		return;
	save = ind->first_n;
	delete_node(ind->first_n,ind);
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
		node = ind_b->first_n;
		ind_b->first_n = ind_b->first_n;
		ind_b->last_n = ind_b->first_n;
	}
	ind_b->size += 1;
	write(1,"pb\n",3);
}

void push_b_to_a(a_index *ind, b_index *ind_b)
{
	list *save;
	list *stock;
	list *node ;

	if (!ind_b->first_n)
		return;
	save = ind_b->first_n;
	delete_node_b(ind_b->first_n,ind_b);
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
		node = ind->first_n;
		ind->first_n = ind->first_n;
		ind->last_n = ind->first_n;
	}
	ind->size += 1;
	write(1,"pa\n",3);
}