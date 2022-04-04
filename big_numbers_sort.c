/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_numbers_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 09:47:05 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/03 13:24:29 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	return_in_place(t_a_index *ind, t_b_index *ind_b)
{
	t_moves	*mv;

	mv = malloc(sizeof(t_moves));
	if (!mv)
		exit(1);
	while (ind_b->size)
	{
		best_b_to_push(mv, ind_b, ind);
		ft_rot(mv, ind, ind_b);
		push_b_to_a(ind, ind_b);
	}
	if (check_nearly_sroted(ind))
		final_sort(ind);
	free(mv);
}

void	best_b_to_push(t_moves *mv, t_b_index *ind_b, t_a_index *ind)
{
	int		best;
	int		i;
	t_list	*t;
	t_moves	*temp_mv;

	temp_mv = NULL;
	i = -1;
	t = ind_b->first_n;
	best = 10000;
	temp_mv = ma_pro_mv(temp_mv);
	while (++i < ind_b->size)
	{
		count_moves(ind, t, temp_mv);
		b_count_moves(ind_b, t, temp_mv);
		if (best > calculate_b(temp_mv) + calculate_a(temp_mv))
		{
			best = calculate_b(temp_mv) + calculate_a(temp_mv);
			mv->ra = temp_mv->ra;
			mv->rra = temp_mv->rra;
			mv->rb = temp_mv->rb;
			mv->rrb = temp_mv->rrb;
		}
		t = t->next;
	}
	free(temp_mv);
}

void	rot_remaining(t_moves *mv, t_a_index *ind, t_b_index *ind_b)
{
	while (mv->rb)
	{
		ft_rb(ind_b);
		mv->rb--;
	}
	while (mv->rrb)
	{
		ft_rrb(ind_b);
		mv->rrb--;
	}
	while (mv->ra)
	{
		ft_ra(ind);
		mv->ra--;
	}
	while (mv->rra)
	{
		ft_rra(ind);
		mv->rra--;
	}
}

void	ft_rot(t_moves *mv, t_a_index *ind, t_b_index *ind_b)
{
	while (mv->ra && mv->rb)
	{
		ft_rr(ind, ind_b);
		mv->ra--;
		mv->rb--;
	}
	while (mv->rra && mv->rrb)
	{
		ft_rrr(ind, ind_b);
		mv->rra--;
		mv->rrb--;
	}
	rot_remaining(mv, ind, ind_b);
}

void	b_count_moves(t_b_index *ind_b, t_list *t, t_moves *mv)
{
	mv->rb = 0;
	mv->rrb = 0;
	if (ft_indix_b(ind_b, t->data) == ind_b->size / 2 && mv->ra)
		mv->rrb = node_to_top_b(ind_b, t->data);
	else if (ft_indix_b(ind_b, t->data) == ind_b->size / 2 && mv->rra)
		mv->rb = ft_indix_b(ind_b, t->data);
	else if (ft_indix_b(ind_b, t->data) > ind_b->size / 2)
		mv->rrb = node_to_top_b(ind_b, t->data);
	else
		mv->rb = ft_indix_b(ind_b, t->data);
}
