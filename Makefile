NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT_DIR = libft/
INCLUDE = ./libft/libft.a

SRCS = push_swap.c parse.c stack_1.c stack_2.c error.c swap.c push.c \
		rotate.c rev_rotate.c sort_three.c turk.c turk2.c utils.c cost.c \

OBJS = $(SRCS:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $(<) -o $(@)

all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

clean:
	@make -s -C $(LIBFT_DIR) clean 
	@rm -rf $(OBJS)

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean 
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
