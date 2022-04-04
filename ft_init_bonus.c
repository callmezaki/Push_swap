/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:59:24 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/03 13:26:22 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_list	*init_node(t_list *node, char *data)
{
	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = ft_atoi(data);
	node->prev = node;
	node->next = node;
	return (node);
}

void	init_list(char **args, t_a_index *ind, int i)
{
	t_list	*node_last;
	t_list	*node_first;
	t_list	*node_next;
	t_list	*node;

	node = NULL;
	node = init_node(node, args[0]);
	node_first = node;
	while (args[++i])
	{
		node_next = malloc(sizeof(t_list));
		if (!node_next)
			return ;
		node_next->data = ft_atoi(args[i]);
		node_next->next = node_first;
		node->next = node_next;
		node_last = node;
		node = node->next;
		node->prev = node_last;
	}
	node_last = node;
	node = node->next;
	node->prev = node_last;
	ind->first_n = node_first;
	ind->size = i;
}

void	init_list_b(t_b_index *ind_b)
{
	ind_b->first_n = NULL;
	ind_b->last_n = NULL;
	ind_b->size = 0;
}

int	get_nb_count(int ac, char **av)
{
	int		i;
	int		j;
	int		x;
	char	**temp;

	i = 1;
	x = 0;
	while (i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			j = 0;
			temp = ft_split(av[i], ' ');
			while (temp[j++])
				x++;
			free_tab(temp);
		}
		else
			x++;
		i++;
	}
	return (x);
}

void	init_args(int ac, char **av, t_args *args)
{
	int		i;
	int		j;
	int		x;
	char	**temp;

	i = 0;
	x = 0;
	args->tab = malloc(sizeof(char *) * get_nb_count(ac, av) + 1);
	while (++i < ac)
	{
		if (ft_strchr(av[i], ' '))
		{
			j = 0;
			temp = ft_split(av[i], ' ');
			if (!temp || !*temp)
				exit(1);
			while (temp[j])
				args->tab[x++] = ft_strdup(temp[j++]);
			free_tab(temp);
		}
		else
			args->tab[x++] = ft_strdup(av[i]);
	}
	args->tab[x] = NULL;
	args->len = x;
}
