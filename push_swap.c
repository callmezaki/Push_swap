/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 06:36:19 by zait-sli          #+#    #+#             */
/*   Updated: 2022/03/16 21:56:45 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_list(int len, char **args,a_index *ind)
{
	list *node_last = NULL;
	list *node_first = NULL;
	list *node = malloc(sizeof(list));
	list *node_next;
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
	node->data = 1;
	ind->first_n = node_first;
	ind->last_n = node_last;
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
			while(temp[j])
			{
				x++;
				j++;
			}
			free_tab(temp);
		}
		else
			x++;
		i++;
	}
	printf("\n%d\n",x);
	return(x);
}

a_args *init_args(int ac, char **av, a_args *args)
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
			while(temp[j])
				args->tab[x++] = strdup(temp[j++]);
		}
		else
			args->tab[x++] = strdup(av[i]);
		i++;
	}
	args->tab[x + 1] = NULL;
	args->len = x;
	printf("\n%d\n",x);
	return(args);
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

int main (int ac, char **av)
{
	int start = 1;
	int i = 0;
	if (ac == 1)
		exit(EXIT_FAILURE);
	a_index *ind = malloc(sizeof(a_index));
	b_index *ind_b = malloc(sizeof(b_index));
	a_lis *lis = malloc(sizeof(a_lis));
	list *node;
	a_args *args = malloc(sizeof(a_args));
	args = init_args(ac, av, args);
	check_isdigit(args->len,args->tab);
	check_int(args->len,args->tab);
	check_duplictes(args->len,args->tab);
	init_list(args->len,args->tab,ind);
	free_tab(args->tab);
	init_list_b(ind_b);
	ind->size = args->len;
	// printf("\n%d\n",node->data);
	// node = ind->first_n;
	// push_b_to_a(ind,ind_b);
	get_best(lis,ind, ind->first_n);
	// ft_rra(ind);
	while(ind->size)
	{
		push_a_to_b(ind,ind_b);
	}
	// ind_b->size += 1; 
	// ft_sa(ind->first_n);
	// delete_node(node,ind);
	i = 0;
	node = ind_b->first_n;
	while(i < ind_b->size)
	{
		printf("%d\n",node->data);
		node = node->next;
		i++;
	}
	free(ind);
	free(ind_b);
	free(lis);
	free(args);
	while(1);
	return(0);
}
