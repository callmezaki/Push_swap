/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:18:25 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/03 13:44:12 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_a_index *ind)
{
	t_list	*temp;

	if (ind->size == 0)
		return ;
	temp = malloc(sizeof(t_list));
	if (!temp)
		exit(1);
	temp->data = ind->first_n->data;
	ind->first_n->data = ind->first_n->next->data;
	ind->first_n->next->data = temp->data;
	free(temp);
}

void	ft_sb(t_b_index *ind_b)
{
	t_list	*temp;

	if (ind_b->size == 0)
		return ;
	temp = malloc(sizeof(t_list));
	if (!temp)
		exit(1);
	temp->data = ind_b->first_n->data;
	ind_b->first_n->data = ind_b->first_n->next->data;
	ind_b->first_n->next->data = temp->data;
	free(temp);
}

void	ft_ss(t_b_index *ind_b, t_a_index *ind)
{
	t_list	*temp_a;
	t_list	*temp_b;

	if (ind->size == 0 || ind_b->size == 0)
		return ;
	temp_a = malloc(sizeof(t_list));
	if (!temp_a)
		exit(1);
	temp_b = malloc(sizeof(t_list));
	if (!temp_b)
		exit(1);
	temp_a->data = ind->first_n->data;
	ind->first_n->data = ind->first_n->next->data;
	ind->first_n->next->data = temp_a->data;
	temp_b->data = ind_b->first_n->data;
	ind_b->first_n->data = ind_b->first_n->next->data;
	ind_b->first_n->next->data = temp_b->data;
	free(temp_a);
	free(temp_b);
}

void	ft_ra(t_a_index *ind)
{
	if (ind->size == 0)
		return ;
	ind->first_n = ind->first_n->next;
}

void	ft_rb(t_b_index *ind)
{
	if (ind->size == 0)
		return ;
	ind->first_n = ind->first_n->next;
}
