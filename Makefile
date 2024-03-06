# https://github.com/codam-coding-college/MLX42/blob/master/docs/Basics.md

NAME				= fdf
CC 					= cc
# CFLAGS 				= -Wall -Werror -Wextra
MLX_HEADERS			= -I lib/MLX42/include
MY_HEADERS			= -I inc

LIB_LIATH	= lib/lib_liath/lib_liath.a
# 		MLX42:
LIBS				= lib/MLX42/build/libmlx42.a $(LIB_LIATH) -ldl -lglfw -pthread -lm #-fsanitize=address -g
SRC					= src/main.c
OBJ					= $(SRC:.c=.o)

all: $(NAME)
# cmake -I ./MLX42/include -B ./MLX42/build && make - C ./MLX42/build -j4 $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "Creating object files, static library file and fdf executable"

%.o : %.c $(LIB_LIATH)
	@$(CC) $(CFLAGS) $(MLX_HEADERS) $(MY_HEADERS) -o $@ -c $<

$(LIB_LIATH):
	@make -C lib/lib_liath/

clean: 
	@-rm -f $(OBJ)
	@echo "Removing all object files"
	@make clean -C lib/lib_liath/ -s

fclean: clean
	@-rm -f $(NAME)
	@echo "Removing fdf executable"
	@make fclean -C lib/lib_liath/ -s

re: fclean all

.PHONY: all clean fclean re

