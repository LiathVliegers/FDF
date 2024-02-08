# https://github.com/codam-coding-college/MLX42/blob/master/docs/Basics.md

NAME	= fdf
CC 		= cc
CFLAGS 	= -Wall -Werror -Wextra
HEADERS	= -I MLX42/include
LIBS	= MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm 
SRC		= main.c
OBJ		= $(SRC:.c=.o)

all: $(NAME)
# cmake -I ./MLX42/include -B ./MLX42/build && make - C ./MLX42/build -j4 $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "Creating object files and fdf executable"

%.o : %.c
	@$(CC) $(CFLAGS) $(HEADERS) -o $@ -c $< 

clean: 
	@-rm -f $(OBJ)
	@echo "Removing object files"

fclean:
	@-rm -f $(NAME)
	@echo "Removing fdf executable"

re: fclean all

.PHONY: all clean fclean re

