NAME = push_swap
BONUS_NAME = checker

SRCS = push_swap.c initialize_structures.c free.c stack_operations_utils.c \
	stack_operations.c print_msg.c sort.c push_swap_utils.c stack_operations_utils2.c \
	stack_operations_utils3.c sort_utils.c sort_utils2.c sort_utils3.c push_swap_utils2.c \
	algo.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = push_swap_bonus.c initialize_structures.c free.c stack_operations_utils.c \
	stack_operations.c print_msg.c sort.c push_swap_utils.c stack_operations_utils2.c \
	stack_operations_utils3.c sort_utils.c sort_utils2.c sort_utils3.c push_swap_utils2.c \
	algo.c $(PATH_GET_LINE)/get_next_line.c $(PATH_GET_LINE)/get_next_line_utils.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

# LIBFT
PATH_LIBFT = ./libft
AR_LIBFT = $(PATH_LIBFT)/libft.a

# GET_NEXT_LINE
PATH_GET_LINE = ./libft/get_next_line

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

all: $(NAME)

$(NAME):	$(OBJS)
	@make -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(AR_LIBFT) -o $(NAME)

bonus:	$(BONUS_NAME)

$(BONUS_NAME):	$(OBJS_BONUS)
	@make -C $(PATH_LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(AR_LIBFT) -o $(BONUS_NAME)

clean:
	@make clean -C $(PATH_LIBFT)
	@rm -f $(OBJS)
	@rm -f $(OBJS_BONUS)

fclean:	clean
	@make fclean -C $(PATH_LIBFT)
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re: fclean all
