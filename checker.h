/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zait-sli <zait-sli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:10:15 by zait-sli          #+#    #+#             */
/*   Updated: 2022/04/06 15:13:12 by zait-sli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# define BUFFER_SIZE 3

typedef struct s_list
{
	int				data;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_index
{
	t_list	*first_n;
	t_list	*last_n;
	int		size;

}	t_a_index;

typedef struct st_b_index
{
	t_list	*first_n;
	t_list	*last_n;
	int		size;

}	t_b_index;

typedef struct s_args
{
	char	**tab;
	int		len;

}	t_args;
typedef struct s_moves
{
	int	indix_a;
	int	indix_b;
	int	ra;
	int	rra;
	int	rb;
	int	rrb;

}	t_moves;

long long	ft_atoi(const char *str);
int			ft_isdigit(int c);
int			check_isdigit(int ac, char **av);
int			check_duplictes(int ac, char **av);
int			check_int(int ac, char **av);
size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		**ft_split(char const *s, char c);
void		ft_sa(t_a_index *ind);
void		ft_sb(t_b_index *ind_b);
void		ft_ss(t_b_index *ind_b, t_a_index *ind);
void		ft_ra(t_a_index *ind);
void		ft_rb(t_b_index *ind_b);
void		ft_rr(t_a_index *ind, t_b_index *ind_b);
void		ft_rra(t_a_index *ind);
void		ft_rrb(t_b_index *ind);
void		ft_rrr(t_a_index *ind, t_b_index *ind_b);
void		delete_node(t_list *from, t_a_index *ind);
void		delete_node_b(t_list *from, t_b_index *ind);
void		push_a_to_b(t_a_index *ind, t_b_index *ind_b);
void		push_b_to_a(t_a_index *ind, t_b_index *ind_b);
void		free_tab(char **tab);
char		*ft_strdup(const char *src);
int			check_sroted(t_a_index *ind);
void		init_list(char **args, t_a_index *ind, int i);
void		init_list_b(t_b_index *ind_b);
int			get_nb_count(int ac, char **av);
void		init_args(int ac, char **av, t_args *args);
char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strchr(const char *s, int c);
char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
void		free_stacks(t_a_index *ind, t_b_index *ind_b);
t_a_index	*ma_pro_a(t_a_index *ind);
t_b_index	*ma_pro_b(t_b_index *ind);
t_args		*ma_pro_args(t_args *args);
char		**ma_pro_tab(char **tab, int len);

#endif