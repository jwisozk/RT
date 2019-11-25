# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/29 14:38:14 by jwisozk           #+#    #+#              #
#    Updated: 2019/10/13 22:25:39 by twill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_putchar.c		\
	  ft_putstr.c		\
	  ft_strcmp.c		\
	  ft_strlen.c		\
	  ft_putnbr.c		\
	  ft_strdup.c		\
	  ft_isalpha.c		\
	  ft_isdigit.c		\
	  ft_isalnum.c		\
	  ft_isascii.c		\
	  ft_isprint.c		\
	  ft_toupper.c		\
	  ft_tolower.c		\
	  ft_putchar_fd.c	\
	  ft_putstr_fd.c	\
	  ft_putnbr_fd.c	\
	  ft_putendl.c		\
	  ft_putendl_fd.c	\
	  ft_strncmp.c		\
	  ft_strcpy.c		\
	  ft_strncpy.c		\
	  ft_strcat.c		\
	  ft_strncat.c		\
	  ft_strlcat.c		\
	  ft_strchr.c		\
	  ft_strrchr.c		\
	  ft_strstr.c		\
	  ft_strnstr.c		\
	  ft_atoi.c			\
	  ft_itoa.c			\
	  ft_memset.c		\
	  ft_bzero.c		\
	  ft_memcpy.c		\
	  ft_memccpy.c		\
	  ft_memmove.c		\
	  ft_memchr.c		\
	  ft_memcmp.c		\
	  ft_memalloc.c		\
	  ft_memdel.c		\
	  ft_strnew.c		\
	  ft_strdel.c		\
	  ft_strclr.c		\
	  ft_striter.c		\
	  ft_striteri.c		\
	  ft_strmap.c		\
	  ft_strmapi.c		\
	  ft_strequ.c		\
	  ft_strnequ.c		\
	  ft_strsub.c		\
	  ft_strjoin.c		\
	  ft_strtrim.c		\
	  ft_strsplit.c		\
	  ft_lstnew.c		\
	  ft_lstdelone.c	\
	  ft_lstdel.c   	\
	  ft_lstadd.c   	\
	  ft_lstiter.c   	\
	  ft_lstmap.c   	\
	  ft_strrev.c   	\
	  ft_lstadd_back.c	\
	  ft_free_all.c		\
	  ft_del.c          \
	  get_next_line.c	\
	  ft_isspace.c		\
	  ft_atoi_base.c    \
	  ft_atof.c         \
	  ft_gc.c           \
	  ft_malloc.c       \
	  ft_clean.c        \
	  ft_print.c

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
DEPS = libft.h ft_gc.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(DEPS)
	gcc -c $(FLAGS) $< -I.

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all fclean re clean
