/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:44:27 by zait-sli          #+#    #+#             */
/*   Updated: 2022/03/23 03:37:02 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int check_isdigit(int len, char **args)
{
	int i = 0;
	int j = 0;
	
	while(i < len)
	{
		j = 0;
		if (!ft_strlen(args[i]))
		{
			write(1," hmmm\n",7);
			exit(EXIT_FAILURE);
		}
		while(args[i][j])
		{
			if ((args[i][j] == '-' || args[i][j] == '+') && j == 0)
				j++;
			if (!ft_isdigit(args[i][j]))
			{
				write(1,args[i],ft_strlen(args[i]));
				write(1," this is not a digit brother\n",30);
				exit(EXIT_FAILURE);
				return(0);
			}
			j++;
		}
		i++;
	}
	return(1);
}

int check_duplictes(int len, char **args)
{
	int i;
	int j;

	i = 0;

	while(args[i])
	{
		j = i + 1;
		while(j < len)
		{
			if (atoi(args[i]) == atoi(args[j]))
			{
				write(1,args[i],strlen(args[i]));
				write(1," is a duplicated\n",18);
				exit(EXIT_FAILURE);
				return(0);
			}
			j++;
		}
		i++;
	}
	return(1);
}

int check_int(int len,char **args)
{
	int i = 0;

	while(i < len)
	{
		if (ft_atoi(args[i]) > 2147483647 || ft_atoi(args[i]) < -2147483648)
		{
			write(1,args[i],strlen(args[i]));
			write(1," number is over int max or min\n",32);
			exit(EXIT_FAILURE);
			return(0);
		}
		i++;
	}
	return(1);
}