/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 06:36:19 by zait-sli          #+#    #+#             */
/*   Updated: 2022/03/22 02:13:11 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_min(list *fisrt,int size)
{
	list *t;
	int i = 0;
	int min;

	t = fisrt;
	min = t->data;
	while(i < size)
	{
		if (t->data < min)
			min = t->data;
		i++;
		t = t->next;
	}
	return(min);
}

int get_max(list *fisrt,int size)
{
	list *t;
	int i = 0;
	int max;

	t = fisrt;
	max = t->data;
	while(i < size)
	{
		if (t->data > max)
			max = t->data;
		i++;
		t = t->next;
	}
	return(max);
}

void return_in_place(a_index *ind , b_index *ind_b)
{
	int s;
	int i = 0;
	int j = 0;
	list *temp = ind->first_n;

	while(ind_b->size)
	{
		j = 0;
		while(ind_b->size)
		{
			s = ind_b->first_n->data;
			if (get_max(ind->first_n,ind->size) == ind->first_n->data && s > ind->first_n->data)
			{
				ft_ra(ind);
				push_b_to_a(ind, ind_b);
				// print_stacks(ind,ind_b);
			}
			// else if (s < ind->first_n->data && s > ind->first_n->next ->data)
			// {
			// 	ft_rra(ind);
			// 	push_b_to_a(ind, ind_b);
			// 	print_stacks(ind,ind_b);
			// }
			else if (s < ind->first_n->data && s > ind->first_n->prev ->data)
			{
				push_b_to_a(ind, ind_b);
			}
			else if (s > ind->first_n->data && s < ind->first_n->next ->data)
			{
				ft_ra(ind);
				push_b_to_a(ind, ind_b);
			}
			else if (s < ind->first_n->data && s > ind->first_n->next ->data)
			{
				push_b_to_a(ind, ind_b);
			}
			else if (get_min(ind->first_n,ind->size) > s)
			{
				while(ind->first_n->data != get_min(ind->first_n,ind->size))
				ft_ra(ind);
				push_b_to_a(ind, ind_b);
			}
			else if (get_max(ind->first_n,ind->size) < s)
			{
				while(ind->first_n->data != get_max(ind->first_n,ind->size))
					ft_ra(ind);
				ft_ra(ind);
				push_b_to_a(ind, ind_b);
			}
			else
			{
				while (s > ind->first_n->data && s > ind->first_n->next->data)
					ft_rra(ind);
				if (s < ind->first_n->data && s > ind->first_n->next ->data)
				{
					ft_rra(ind);
					push_b_to_a(ind, ind_b);
				}
				else if (s > ind->first_n->data && s < ind->first_n->next ->data)
				{
					ft_ra(ind);
					push_b_to_a(ind, ind_b);
				}
				else if (s < ind->first_n->data && s > ind->first_n->prev ->data)
				{
					push_b_to_a(ind, ind_b);
				}
				else
					push_b_to_a(ind, ind_b);
			}
				
			j++;
		}
		i++;
	}
}

void final_sort(a_index *ind)
{
	int s = get_min(ind->first_n , ind->size);

	while(ind->first_n->data != s)
		ft_ra(ind);
}

void print_stacks(a_index *ind, b_index *ind_b)
{
	list *node;
	int i = 0;
	
		i  = 0;
	node = ind->first_n;
	while(i < ind->size)
	{
		printf("stack a = <%d>\n",node->data);
		node = node->next;
		i++;
	}
	printf("<---------------->\n");
	i = 0;
	node = ind_b->first_n;
	while(i < ind_b->size)
	{
		printf("stack b = <%d>\n",node->data);
		node = node->next;
		i++;
	}
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
	init_args(ac, av, args);
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
	if (check_sroted(ind))
	{
		puts("sorted");
		exit(0);
	}
	push_intilis(ind, ind_b, lis);
	return_in_place(ind,ind_b);
	if (check_nearly_sroted(ind))
	{
		// puts("nearly_sorted");
		final_sort(ind);
		// if (check_sroted(ind))
		// 	// puts("sorted");/
	}
	// while(ind->size)
	// {
		// push_a_to_b(ind,ind_b);
	// }
	// while (i < lis->len)
	// {
	// 	printf("%d\n",lis->order[i]);
	// 	i++;
	// }
	// delete_node(ind->first_n,ind);
	// delete_node(ind->first_n,ind);
	// print_stacks(ind,ind_b);
	// i  =0 ;
	// node = ind->first_n;
	// while(i < ind->size)
	// {
	// 	printf("stack a = <%d>\n",node->data);
	// 	node = node->next;
	// 	i++;
	// }
	// printf("<---------------->\n");
	// i = 0;
	// node = ind_b->first_n;
	// while(i < ind_b->size)
	// {
	// 	printf("stack b = <%d>\n",node->data);
	// 	node = node->next;
	// 	i++;
	// }
	// ft_rra(ind);
	return(0);
}


