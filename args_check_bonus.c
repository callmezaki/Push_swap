/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:44:27 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/06 16:08:05 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	check_isdigit(int len, char **args)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = 0;
		if (!ft_strlen(args[i]))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		while (args[i][j])
		{
			if ((args[i][j] == '-' || args[i][j] == '+') && j == 0)
				j++;
			if (!ft_isdigit(args[i][j]))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
	}
	return (1);
}

int	check_duplictes(int len, char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = i + 1;
		while (j < len)
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
			{
				write(1, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int(int len, char **args)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (ft_atoi(args[i]) > 2147483647 || ft_atoi(args[i]) < -2147483648)
		{
			write(1, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
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
