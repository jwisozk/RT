# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/09 13:59:01 by jwisozk           #+#    #+#              #
#    Updated: 2019/11/23 22:46:35 by jwisozk          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADER = rt.h
LIBFT = libft/libft.a
MAKE_LIBFT = make -C libft
SDL2_FLAGS = -F SDL2 -framework SDL2
# SDL2_IMAGE = -F SDL2 -framework SDL2_image
SOURCE = src/main.c \
         src/ft_sdl2_main.c \
         src/sdl2/keys/ft_sdl2_key_quit.c
OBJ = $(SOURCE:.c=.o)

#all: make_libft $(NAME)
all: $(NAME)

#$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
#	$(CC) $(CFLAGS) $^ $(LIBFT) $(LIBMLX) $(FRAMEWORKS) -o $(NAME)
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(NAME) $(SDL2_FLAGS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $<

#make_libft:
#	$(MAKE_LIBFT)

clean:
	rm -f $(OBJ)
#	$(MAKE_LIBFT) clean

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
#	$(MAKE_LIBFT) fclean

re: fclean all

.PHONY: all fclean re clean