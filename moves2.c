/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 21:18:25 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/06 14:53:06 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr(t_a_index *ind, t_b_index *ind_b)
{
	if (ind->size == 0 || ind_b->size == 0)
		return ;
	ind->first_n = ind->first_n->next;
	ind_b->first_n = ind_b->first_n->next;
	write(1, "rr\n", 3);
}

void	ft_rra(t_a_index *ind)
{
	if (ind->size == 0)
		return ;
	ind->first_n = ind->first_n->prev;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_b_index *ind)
{
	if (ind->size == 0)
		return ;
	ind->first_n = ind->first_n->prev;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_a_index *ind, t_b_index *ind_b)
{
	if (ind->size == 0 || ind_b->size == 0)
		return ;
	ind->first_n = ind->first_n->prev;
	ind_b->first_n = ind_b->first_n->prev;
	write(1, "rrr\n", 4);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
