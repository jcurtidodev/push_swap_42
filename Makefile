# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcurtido <jcurtido@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 14:17:07 by jcurtido          #+#    #+#              #
#    Updated: 2024/12/05 15:54:05 by jcurtido         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Direectories
LIBFT_DIR = libft

# Soucer files
LIBFT_SRC = $(LIBFT_DIR)/ft_atoi.c $(LIBFT_DIR)/ft_isascii.c $(LIBFT_DIR)/ft_memcmp.c $(LIBFT_DIR)/ft_strchr.c $(LIBFT_DIR)/ft_strncmp.c $(LIBFT_DIR)/ft_toupper.c $(LIBFT_DIR)/ft_bzero.c $(LIBFT_DIR)/ft_isdigit.c $(LIBFT_DIR)/ft_memcpy.c $(LIBFT_DIR)/ft_strlcat.c $(LIBFT_DIR)/ft_strnstr.c $(LIBFT_DIR)/ft_isalnum.c $(LIBFT_DIR)/ft_isprint.c $(LIBFT_DIR)/ft_memmove.c $(LIBFT_DIR)/ft_strlcpy.c $(LIBFT_DIR)/ft_strrchr.c $(LIBFT_DIR)/ft_isalpha.c $(LIBFT_DIR)/ft_memchr.c $(LIBFT_DIR)/ft_memset.c $(LIBFT_DIR)/ft_strlen.c $(LIBFT_DIR)/ft_tolower.c $(LIBFT_DIR)/ft_strjoin.c $(LIBFT_DIR)/ft_calloc.c $(LIBFT_DIR)/ft_isprint.c $(LIBFT_DIR)/ft_strtrim.c $(LIBFT_DIR)/ft_substr.c $(LIBFT_DIR)/ft_strdup.c $(LIBFT_DIR)/ft_split.c $(LIBFT_DIR)/ft_itoa.c $(LIBFT_DIR)/ft_strmapi.c $(LIBFT_DIR)/ft_striteri.c $(LIBFT_DIR)/ft_putchar_fd.c $(LIBFT_DIR)/ft_putstr_fd.c $(LIBFT_DIR)/ft_putendl_fd.c $(LIBFT_DIR)/ft_putnbr_fd.c $(LIBFT_DIR)/ft_get_next_line.c $(LIBFT_DIR)/ft_itoa_base.c $(LIBFT_DIR)/ft_lstnew.c $(LIBFT_DIR)/ft_lstadd_front.c $(LIBFT_DIR)/ft_lstsize.c $(LIBFT_DIR)/ft_lstlast.c $(LIBFT_DIR)/ft_lstadd_back.c $(LIBFT_DIR)/ft_lstdelone.c $(LIBFT_DIR)/ft_lstclear.c $(LIBFT_DIR)/ft_lstiter.c $(LIBFT_DIR)/ft_lstmap.c $(LIBFT_DIR)/ft_printf.c $(LIBFT_DIR)/ft_printf_utils.c $(LIBFT_DIR)/ft_printf_writers.c
PUSH_SWAP_SRC = push_swap.c push_swap_utils.c push_swap_moves.c main_utils.c index_utils.c

# Objects
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)

# Variables
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar
ARFLAGS = rcs
NAME = push_swap.a

# Targets
all: libft $(NAME)

# Build libft library
libft:
	$(make) -C $(LIBFT_DIR)

# Build the static library (including both libft and push_swap objects)
$(NAME): $(LIBFT_OBJ) $(PUSH_SWAP_OBJ)
	$(AR) $(ARFLAGS) $@ $^

# Compile .c files to .o files
%.o: %.c Makefile push_swap.h $(LIBFT_DIR)/Makefile $(LIBFT_DIR)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Compile the main with the library
#	$(CC) $(CFLAGS)

# Compile the main with the library
#push_swap: main.c $(NAME)
#	$(CC) $(CFLAGS) mian.c $(NAME) -o push_swap

# Clean objects and library
clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(PUSH_SWAP_OBJ)

# Full clean, including the static library and executable
fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME) push_swap

re: fclean all
