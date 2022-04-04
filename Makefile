NAME = push_swap
CHECK = checker
INCLUDE = push_swap.h
INCLUDE_B = checker.h
SRC =	push_swap.c \
		ft_atoi.c \
		args_check.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_split.c \
		ft_strdup.c \
		moves.c \
		moves2.c \
		lis.c \
		pa_pb.c \
		sorting.c \
		ft_init.c \
		sort_utils.c \
		small_numbers_sort.c \
		big_numbers_sort.c \
		best_move.c \
		protection.c \
		
SRC_B =	checker.c \
		ft_strchr.c \
		ft_strcmp.c \
		moves_bonus.c \
		moves_bonus2.c \
		pa_pb_bonus.c \
		ft_init_bonus.c \
		args_check_bonus.c \
		ft_atoi_bonus.c \
		ft_split_bonus.c \
		ft_strdup_bonus.c \
		get_next_line.c \
		get_next_line_utils.c \
		protection_bonus.c \

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@gcc  $(CFLAGS) -I $(INCLUDE) -o $@ $^   

bonus: $(CHECK)

$(CHECK):$(OBJ_B)
	@gcc  $(CFLAGS) -I $(INCLUDE_B) -o $(CHECK) $^ 

clean:
	@rm -f $(OBJS) $(OBJ_B)
fclean: clean
	@rm -f $(NAME) $(CHECK)
re: fclean all