NAME = push_swap
BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft/
INCLUDE = ./libft/libft.a

MAIN = push_swap.c

SRCS = parse.c stack_1.c stack_2.c error.c swap.c push.c \
		rotate.c rev_rotate.c sort_three.c turk.c turk2.c cost.c \

BSRCS = checker.c

MAIN_OBJ = $(MAIN:.c=.o)

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $(<) -o $(@)

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(MAIN_OBJ) $(OBJS)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJS) -o $(NAME) $(INCLUDE)

$(BONUS): $(OBJS) $(BOBJS)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(BOBJS) $(OBJS) -o $(BONUS) $(INCLUDE)

clean:
	@make -s -C $(LIBFT_DIR) clean 
	@rm -rf $(MAIN_OBJ) $(OBJS) $(BOBJS)

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean 
	@rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus
