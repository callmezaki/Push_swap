/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 14:35:00 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/06 12:29:00 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

char	**ma_pro_tab(char **tab, int len)
{
	tab = malloc(sizeof(char *) * len);
	if (!tab)
		exit(1);
	return (tab);
}
