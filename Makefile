NAME = push_swap
INCLUDE = push_swap.h
SRC =	push_swap.c \
		ft_atoi.c \
		args_check.c \
		ft_strchr.c \
		ft_strlen.c \
		ft_split.c \
		ft_strdup.c \
		moves.c \
		lis.c \
		pa_pb.c \
		sorting.c \
		ft_init.c \

CFLAGS = -g

OBJS = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@rm -f  $(OBJ_B) $(NAME)
	@gcc  $(CFLAGS) -I $(INCLUDE) -o $@ $^   

# bonus : $(OBJ_B)
# 	@rm -f  $(OBJS) $(NAME)
# 	@gcc  $(CFLAGS) -I $(INCLUDE_B) -o $(NAME) $^ 

clean:
	@rm -f $(OBJS) $(OBJ_B)
fclean: clean
	@rm -f $(NAME)
re: fclean all