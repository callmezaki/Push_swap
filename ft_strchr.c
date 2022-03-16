/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:07:25 by zait-sli          #+#    #+#             */
/*   Updated: 2022/03/11 21:52:33 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*sf;

	sf = (char *)s;
	i = 0;
	while ((size_t)i <= ft_strlen(sf))
	{
		if (s[i] == (char)c)
		{
			return (&((char *)sf)[i]);
		}
		i++;
	}
	return (0);
}
