NAME 				= lib_liath.a
CC					= cc
CFLAGS 				= -Wall -Wextra -Werror
OBJDIR				= .obj_lib
SRC_DIR				= src
SRC = \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_memset.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strdup.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_atoi.c \
	ft_itoa.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_split.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstadd_back_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_printf_charstring.c \
	ft_printf_hexadecimalsptr.c \
	ft_printf_number.c \
	ft_printf_unsigned_number.c \
	ft_printf.c \
	get_next_line_utils.c \
	get_next_line.c
OBJ					= $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJ)
	@ar rcs $(NAME) $(OBJ)

$(OBJDIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $^

clean:
	@-rm -rf $(OBJDIR)

fclean: clean
	@echo "Removing the lib_liath.a file."
	@-rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re