/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:18:25 by zait-sli          #+#    #+#             */
/*   Updated: 2022/03/16 22:53:33 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sa(a_index *ind)
{
	list *temp;

	temp->data = ind->first_n->data;
	ind->first_n->data = ind->first_n->next->data;
	ind->first_n->next->data = temp->data;
	write(1,"sa\n",4);
}

void ft_sb(b_index *ind_b)
{
	list *temp;

	temp->data = ind_b->first_n->data;
	ind_b->first_n->data = ind_b->first_n->next->data;
	ind_b->first_n->next->data = temp->data;
	write(1,"sb\n",4);
}

void ft_ss(b_index *ind_b,a_index *ind)
{
	list *temp_a;
	list *temp_b;

	temp_a->data = ind->first_n->data;
	ind->first_n->data = ind->first_n->next->data;
	ind->first_n->next->data = temp_a->data;

	temp_b->data = ind_b->first_n->data;
	ind_b->first_n->data = ind_b->first_n->next->data;
	ind_b->first_n->next->data = temp_b->data;
	write(1,"ss\n",4);
}

void ft_ra(a_index *ind)
{
	list *temp;

	temp->data = ind->first_n->data;
	ind->first_n->data = ind->first_n->prev->data;
	ind->first_n->prev->data = temp->data;
	write(1,"ra\n",4);
}

void ft_rb(b_index *ind_b)
{
	list *temp;

	temp->data = ind_b->first_n->data;
	ind_b->first_n->data = ind_b->first_n->prev->data;
	ind_b->first_n->prev->data = temp->data;
	write(1,"rb\n",4);
}

void ft_rr(a_index *ind,b_index *ind_b)
{
	list *temp_a;
	list *temp_b;

	temp_a->data = ind->first_n->data;
	ind->first_n->data = ind->first_n->prev->data;
	ind->first_n->prev->data = temp_a->data;

	temp_b->data = ind_b->first_n->data;
	ind_b->first_n->data = ind_b->first_n->prev->data;
	ind_b->first_n->prev->data = temp_b->data;
	write(1,"rr\n",4);
}

void ft_rra(a_index *ind)
{
	ind->first_n = ind->first_n->prev;
	ind->last_n = ind->last_n->prev;
	write(1,"rra\n",4);
}

void ft_rrb(b_index *ind)
{
	ind->first_n = ind->first_n->prev;
	ind->last_n = ind->first_n->prev;
	write(1,"rrb\n",4);
}

void ft_rrr(a_index *ind, b_index *ind_b)
{
	ind->first_n = ind->first_n->prev;
	ind->last_n = ind->first_n->prev;

	ind_b->first_n = ind_b->first_n->prev;
	ind_b->last_n = ind_b->first_n->prev;
	write(1,"rrb\n",4);
}
