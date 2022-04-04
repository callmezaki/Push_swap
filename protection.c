/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:35:00 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/03 13:25:32 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_a_index	*ma_pro_a(t_a_index *ind)
{
	ind = malloc(sizeof(t_a_index));
	if (!ind)
		exit(1);
	return (ind);
}

t_b_index	*ma_pro_b(t_b_index *ind)
{
	ind = malloc(sizeof(t_b_index));
	if (!ind)
		exit(1);
	return (ind);
}

t_args	*ma_pro_args(t_args *args)
{
	args = malloc(sizeof(t_args));
	if (!args)
		exit(1);
	return (args);
}

t_moves	*ma_pro_mv(t_moves *mv)
{
	mv = malloc(sizeof(t_moves));
	if (!mv)
		exit(1);
	return (mv);
}

int	*ma_pro_arr(int *ar, int len)
{
	ar = malloc(sizeof(int) * len);
	if (!ar)
		exit(1);
	return (ar);
}
