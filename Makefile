# https://github.com/codam-coding-college/MLX42/blob/master/docs/Basics.md

NAME				= fdf
CC 					= cc
CFLAGS 				= -Wall -Werror -Wextra -O3
MLX_HEADERS			= -I lib/MLX42/include
MY_HEADERS			= -I inc

LIB_LIATH			= lib/lib_liath/lib_liath.a
MLX42				= lib/MLX42/build/libmlx42.a
LIBS				= lib/MLX42/build/libmlx42.a $(LIB_LIATH) -ldl -lglfw -pthread -lm -fsanitize=address -g
OBJDIR				= .obj
SRC_DIR				= src
SRC						= \
							allocate.c \
							colours_and_utils.c \
							debugging.c \
							defaults.c \
							draw.c \
							errors_and_clear.c \
							keys.c \
							main.c \
							parse_map.c \
							rgb_pixels.c
OBJ					= $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJ) $(MLX42)
	@$(CC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "Creating object files."
	@echo "Creating the lib_liath.a file."
	@echo "Creating the fdf executable file."

$(OBJDIR)/%.o : $(SRC_DIR)/%.c $(LIB_LIATH)
	@$(CC) $(CFLAGS) $(MLX_HEADERS) $(MY_HEADERS) -o $@ -c $<

$(LIB_LIATH):
	@make -C lib/lib_liath/

$(MLX42):
	@cmake -B ./lib/MLX42/build ./lib/MLX42
	@make -C ./lib/MLX42/build -j4
	@echo "Building the MLX42 libmlx42.a file"

clean: 
	@-rm -rf $(OBJDIR)
	@make clean -C lib/lib_liath/ -s
	@echo "Removing all object files."

fclean: clean
	@-rm -f $(NAME)
	@-rm -rf ./lib/MLX42/build
	@make fclean -C lib/lib_liath/ -s
	@echo "Removing the MLX42 libmlx42.a file"
	@echo "Removing fdf executable."

re: fclean all

.PHONY: all clean fclean re
