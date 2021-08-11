NAME = pipex
LIBFT = srcs/Libft
SRC = srcs/main.c srcs/parse.c srcs/utils1.c srcs/utils2.c
CC = gcc -g
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: all clean fclean