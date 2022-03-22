/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:25:14 by zait-sli          #+#    #+#             */
/*   Updated: 2022/03/22 02:12:21 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

a_lis get_lis(a_index *ind, list *node, int start ,a_lis lis)
{
	int i = start;
	lis.len = 0;
	int big = node->data;
	list *temp = node;

	lis.order[lis.len++] = temp->data;
	temp = temp->next;
	if (start == ind->size)
	{
		temp = ind->first_n;
		i = 0;
	}
	while(i < ind->size)
	{
		if(big < temp->data)
		{
			lis.order[lis.len] = temp->data;
			lis.len++;
		}
		if (big <= temp->data)
			big = temp->data;
		temp = temp->next;
		i++;
	}
	return(lis);
}

void get_best(a_lis *lis,a_index *ind, list *node)
{

	a_lis temp;
	int start = 0;
	int i = 0;
	int j;

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

int check_lis(list *tt, a_lis *lis)
{
	int i = 0;

	while(i < lis->len)
	{
		if (tt->data == lis->order[i])
		{
			return(1);
		}
		i++;
	}
	return(0);
}

void push_intilis(a_index *ind, b_index *ind_b, a_lis *lis)
{
	int i = 0;
	int len = ind->size;
	
	while(i < len)
	{
		if  (!check_lis(ind->first_n, lis))
			push_a_to_b(ind,ind_b);
		else
			ft_ra(ind); 
		i++;
	}
	// print_stacks(ind,ind_b);
}