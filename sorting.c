/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:48:06 by zait-sli          #+#    #+#             */
/*   Updated: 2022/03/21 22:52:27 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_nearly_sroted(a_index *ind)
{
	list *temp;
	int len = 0;;
	int j = 0;
	
	temp = ind->first_n;
	while(len < ind->size)
	{
		j = 0;
		while(j < ind->size)
		{
			if (temp->data < temp->next->data)
			{
				temp= temp->next;
				j++;
			}
			else
				break;
		}
		if (j == ind->size - 1)
			return(1);
		temp= temp->next;
		len++;
	}
	return(0);
}

int check_sroted(a_index *ind)
{
	list *temp;
	int len = 0;;
	int j = 0;
	
	temp = ind->first_n;
	while(len < ind->size)
	{
		j = 0;
		while(j < ind->size)
		{
			if (temp->data < temp->next->data)
			{
				temp= temp->next;
				j++;
			}
			else
				break;
		}
		if (j == ind->size - 1)
			return(1);
		len++;
	}
	return(0);
}