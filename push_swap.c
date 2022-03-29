/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 06:36:19 by zait-sli          #+#    #+#             */
/*   Updated: 2022/03/29 02:00:24 by zait-sli         ###   ########.fr       */
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
int ft_indix(a_index *ind, int data)
{
	int count = 0;
	list *temp = ind->first_n;
	while(temp->data != data )
		temp = temp->next;
	while(temp->data != ind->first_n->data)
	{
		temp = temp->prev;
		count++;
	}
	return(count);
}
int ft_indix_b(b_index *ind, int data)
{
	int count = 0;
	list *temp = ind->first_n;
	while(temp->data != data )
		temp = temp->next;
	while(temp->data != ind->first_n->data)
	{
		temp = temp->prev;
		count++;
	}
	return(count);
}
int node_to_top(a_index *ind, int data)
{
	int count = 0;
	list *temp = ind->first_n;
	while(temp->data != data )
		temp = temp->next;
	while(temp->data != ind->first_n->data)
	{
		temp = temp->next;
		count++;
	}
	return(count);
}

int node_to_top_b(b_index *ind_b, int data)
{
	int count = 0;
	list *temp = ind_b->first_n;
	while(temp->data != data )
		temp = temp->next;
	while(temp->data != ind_b->first_n->data)
	{
		temp = temp->next;
		count++;
	}
	return(count);
}
void count_moves(a_index *ind,list *wanted,moves *mv)
{
	int count = 0;
	list *temp;

	temp = ind->first_n;
	mv->ra = 0;
	mv->rra = 0;

	if (get_min(temp,ind->size) > wanted->data)
	{
			// count--;
		// count = node_to_top(ind, get_min(temp,ind->size));
		// printf("kaaaan hnaaa\n");
		while(temp->data != get_min(temp,ind->size))
		{
			count++;
			temp = temp->next;
			// puts("ssssss\n");
		}
		if (ft_indix(ind,temp->data) > ind->size / 2)
		{
			mv->rra = ind->size - ft_indix(ind,temp->data);
			count = mv->rra;
		}
		else
		{
			mv->ra = ft_indix(ind,temp->data);
			count = mv->ra;
		}
	}
	else if (get_max(temp,ind->size) < wanted->data)
	{
		while(temp->prev->data != get_max(temp,ind->size))
		{
			count++;
			temp = temp->next;
		}
		if (ft_indix(ind,temp->data) > ind->size / 2)
		{
			mv->rra = ind->size - ft_indix(ind,temp->data);
			count = mv->rra;
			
		}
		else
		{
			mv->ra = ft_indix(ind,temp->data);
			count = mv->ra;
		}
	}
	else
	{
		while(1)
		{
			if (temp->data > wanted->data && temp->prev->data < wanted->data)
			{
				if (ft_indix(ind,temp->data) > ind->size / 2)
				{
				// printf("\n-----------   %d   -----------------\n",ft_indix(ind,temp->data));
					mv->rra = ind->size - ft_indix(ind,temp->data);
					count = mv->rra;
				}
				else
				{
				// printf("\n-----------   %d   -----------------\n",ft_indix(ind,temp->data));
					mv->ra = ft_indix(ind,temp->data);
					count = mv->ra;
				}
				break;
			}
			temp = temp->next;
		}
		mv->indix_a = count;
	}
	// return(count);
}
void b_count_moves(b_index *ind_b, list *t , moves *mv)
{
	mv->rb = 0;
	mv->rrb = 0;
	if (ft_indix_b(ind_b, t->data) > ind_b->size / 2)
	{
		mv->rrb = node_to_top_b(ind_b, t->data);
		mv->indix_b = mv->rrb;
	}
	else
	{
		mv->rb = ft_indix_b(ind_b,t->data);
		mv->indix_b = mv->rb;
	}
}

void best_b_to_move(moves *mv,b_index *ind_b, a_index *ind)
{
	int to_top;
	int a_moves = 0;
	int best = 1000000;
	int i = 0;
	list *t = ind_b->first_n;
	moves *temp_mv = malloc(sizeof(moves));

	mv->ra = 0;
	mv->rra = 0;
	mv->rb = 0;
	mv->rrb = 0;
	while(i < ind_b->size)
	{
		count_moves(ind, t,temp_mv);
		b_count_moves(ind_b, t, temp_mv);
		a_moves = temp_mv->indix_a;
		to_top = temp_mv->indix_b;
		if (best > to_top + a_moves)
		{
			best = to_top + a_moves;
			mv->ra = temp_mv->ra;
			mv->rra = temp_mv->rra;
			mv->rb = temp_mv->rb;
			mv->rrb = temp_mv->rrb;
		}
		// printf("%d-------\n",mv->rb);
		i++;
		t = t->next;
		// printf("ssssssssss");

	}
}
void ft_rot(moves *mv,a_index *ind, b_index *ind_b)
{

	while(mv->ra && mv->rb)
	{
		ft_rr(ind, ind_b);
		mv->ra--;
		mv->rb--;
	}
	while(mv->rra && mv->rrb)
	{
		ft_rrr(ind,ind_b);
		mv->rra--;
		mv->rrb--;
	}
	while(mv->rb)
	{
		ft_rb(ind_b);
		mv->rb--;
	}
	while(mv->rrb)
	{
		ft_rrb(ind_b);
		mv->rrb--;
	}
	while(mv->ra)
	{
		ft_ra(ind);
		mv->ra--;
	}
	while(mv->rra)
	{
		ft_rra(ind);
		mv->rra--;
	}
}
void return_in_place(a_index *ind , b_index *ind_b)
{
	int temp;
	int len;
	int len2;
	moves *mv = malloc(sizeof(moves));


	
	while(ind_b->size)
	{

		best_b_to_move(mv,ind_b,ind);
		// printf("%d --- \n",mv->ra);
		// printf("%d --- \n",mv->rra);
		// printf("%d --- \n",mv->rb);
		// printf("%d --- \n",mv->rrb);
		// print_stacks(ind,ind_b);
		ft_rot(mv,ind,ind_b);
		// print_stacks(ind,ind_b);
		// if (ind_b->size == 1)
		// 	while(1);
		push_b_to_a(ind, ind_b);
		
		// if (get_min(ind->first_n,ind->size) > ind_b->first_n->data)
		// {
		// 	// temp = count_moves(ind, ind->first_n);
		// 	// while(ind->first_n->prev->data != get_max(ind->first_n,ind->size))
		// 	// {
		// 	// 	if (temp < ind->size / 2)
		// 	// 	{
		// 	// 		ft_rra(ind);
		// 	// 	}
		// 	// 	else
		// 	// 		ft_ra(ind);
		// 	// }
		// 	push_b_to_a(ind, ind_b);
		// }
		// else if (get_max(ind->first_n,ind->size) < ind_b->first_n->data)
		// {
		// 	// temp = count_moves(ind, ind_b->first_n);
		// 	// while(ind->first_n->data != get_min(ind->first_n,ind->size))
		// 	// {
		// 	// 	if (temp > ind->size / 2)
		// 	// 	{
		// 	// 		ft_rra(ind);
		// 	// 	}
		// 	// 	else
		// 	// 		ft_ra(ind);
		// 	// }
		// 	push_b_to_a(ind, ind_b);
		// }
		// else
		// {
		// 	// temp = count_moves(ind, ind_b->first_n);
		// 	// temp = node_to_top(ind, ind->first_n->data);
		// 	// while (1)
		// 	// {
		// 		// if (ind->first_n->data > ind_b->first_n->data && ind->first_n->prev->data < ind_b->first_n->data)
		// 		// {
		// 			push_b_to_a(ind,ind_b);
		// 			// break ;
		// 		// }
		// 		// if (temp > ind->size / 2)
		// 		// {
		// 		// 	ft_rra(ind);
		// 		// }
		// 		// else
		// 		// 	ft_ra(ind);
		// 	// }
		// }
	// printf("\n\n\n\n\n\n\n\n\nssssssssss\n\n\n\n\n\n\n\n\n\n\n\n");
	}
	// free(mv);

}

void final_sort(a_index *ind)
{
	int s = node_to_top(ind, get_min(ind->first_n , ind->size));
	while(ind->first_n->data != get_min(ind->first_n , ind->size))
	{
		if (s > ind->size / 2)
		{
			ft_ra(ind);
		}
		else
		{
			ft_rra(ind);
		}
	}
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
	// print_stacks(ind,ind_b);
	init_list_b(ind_b);
	ind->size = args->len;
	free_tab(args->tab);
	get_best(lis,ind, ind->first_n);
	push_intilis(ind, ind_b, lis);
	return_in_place(ind,ind_b);
	if (check_nearly_sroted(ind))
	{
		// puts("nearly_sorted");
		final_sort(ind);
		// if (check_sroted(ind))
		// 	puts("sorted");
	}
	// if (check_sroted(ind))
	// {
	// 	puts("sorted");
	// 	exit(0);
	// }
	
	free(ind);
	free(ind_b);
	free(lis);
	free(args);
	// while(1);
	return(0);
}


