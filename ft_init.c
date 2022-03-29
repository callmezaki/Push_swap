/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:59:24 by zait-sli          #+#    #+#             */
/*   Updated: 2022/03/28 22:11:40 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_list(int len, char **args,a_index *ind)
{
	list *node_last;
	list *node_first;
	list *node_next;
	list *node = malloc(sizeof(list));
	int i = 1;

	if(!node)
		return ;
	node->data = atoi(args[0]);
    node->prev = node;
    node->next = node;
    node_first = node;
	while(args[i])
	{
		node_next = malloc(sizeof(list));
		if(!node_next)
			return ;
        node_next->data = atoi(args[i]);
        node_next->next = node_first;
        node->next = node_next;
        node_last = node;
        node = node->next;
        node->prev = node_last;
		i++;
	}
	node_last = node;
	node = node->next;
	node->prev = node_last;
	ind->first_n = node_first;
	ind->last_n = node_last;
	ind->size = i;
	// free(node);
	// free(node_next);
}
void	init_list_b(b_index *ind_b)
{
	ind_b->first_n = NULL;
	ind_b->last_n = NULL;
	ind_b->size = 0;
}

int	get_nb_count(int ac, char **av)
{
	int i = 1;
	int j = 0;
	int	x = 0;
	char **temp;

	while(i < ac)
	{
		if(ft_strchr(av[i] ,' '))
		{
			j = 0;
			temp = ft_split(av[i] ,' ');
			while(temp[j++])
				x++;
			free_tab(temp);
		}
		else
			x++;
		i++;
	}
	return(x);
}

void	init_args(int ac, char **av, a_args *args)
{
	int i = 1;
	int j = 0;
	int	x = 0;
	char **temp;

	args->tab = malloc(sizeof(char *) * get_nb_count(ac, av) + 1);
	while(i < ac)
	{
		if(ft_strchr(av[i] ,' '))
		{
			j = 0;
			temp = ft_split(av[i] ,' ');
			if(!temp || !*temp)
				exit(1);
			while(temp[j])
			{
				args->tab[x++] = ft_strdup(temp[j++]);
			}
			free_tab(temp);
		}
		else
		{
			args->tab[x] = ft_strdup(av[i]);
			x++;
		}
		i++;
	}
	args->tab[x] = NULL;
	args->len = x;
}

void free_tab(char **tab)
{
	int i = 0;

	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}