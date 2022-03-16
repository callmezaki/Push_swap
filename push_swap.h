#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_list
{
	int data;
	struct s_list *next;
	struct s_list *prev;
} list;

// typedef struct l_b
// {
// 	int data;
// 	struct l_b *next;
// 	struct l_b *prev;
// } sl_b;

typedef struct s_index
{
	list *first_n;
	list *last_n;
	int size;

}	a_index;

typedef struct sb_index
{
	list *first_n;
	list*last_n;
	int size;

}	b_index;

typedef struct s_lis
{
	int order[10000];
	int len;

}	a_lis;

typedef struct s_args
{
	char **tab;
	int len;

}	a_args;

long long	ft_atoi(const char *str);
int			ft_isdigit(int c);
int			check_isdigit(int ac, char **av);
int			check_duplictes(int ac, char **av);
int			check_int(int ac,char **av);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
char		**ft_split(char const *s, char c);
void		ft_sa(a_index *ind);
void		ft_sb(b_index *ind_b);
void		ft_ss(b_index *ind_b,a_index *ind);
void		ft_ra(a_index *ind);
void		ft_rb(b_index *ind_b);
void		ft_rr(a_index *ind,b_index *ind_b);
void		ft_rra(a_index *ind);
void		ft_rrb(b_index *ind);
void		ft_rrr(a_index *ind, b_index *ind_b);
void		delete_node(list *from,a_index *ind);
void		delete_node_b(list *from,b_index *ind);
void		push_a_to_b(a_index *ind,b_index *ind_b);
void		push_b_to_a(a_index *ind, b_index *ind_b);
a_lis		get_lis(a_index *ind, list *node, int start ,a_lis lis);
void		get_best(a_lis *lis,a_index *ind, list *node);
void		free_tab(char **tab);

#endif