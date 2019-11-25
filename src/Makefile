# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/09 13:59:01 by jwisozk           #+#    #+#              #
#    Updated: 2019/10/13 15:17:32 by twill            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
CC = gcc
CFLAGS = -Wall -Wextra -Werror
HEADERS = rtv1.h
# LIBMLX = minilibx/libmlx.a
FRAMEWORKS = -framework OpenGL -framework AppKit
LIBFT = libft/libft.a
MAKE_LIBFT = make -C libft
# MAKE_LIBMLX = make -C minilibx
SOURCE =	main.c \
			etc_1.c \
			etc_2.c \
			draw.c \
			color.c \
			operations_v.c \
			operations_d.c \
			lighting.c \
			light_create.c \
			light_update.c \
			objects_intersect.c \
			objects_fill.c \
			camera.c \
			camera_create.c \
			camera_update.c \
			objects_create.c \
			geometric_create.c \
			transform.c \
			objects_update.c \
			objects_update_min.c \
			camera_validate.c  \
			objects_validate.c \
			objects_calculate.c \
			light_validate.c \
			scene_get.c \
			scene_extra.c
OBJ = $(SOURCE:.c=.o)

all: make_libft make_libmlx $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX)
	$(CC) $(CFLAGS) $^ $(LIBFT) $(LIBMLX) $(FRAMEWORKS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $<

make_libft:
	$(MAKE_LIBFT)

make_libmlx:
	$(MAKE_LIBMLX)

clean:
	rm -f $(OBJ)
	$(MAKE_LIBFT) clean
	$(MAKE_LIBMLX) clean

fclean:
	rm -f $(OBJ)
	rm -f $(NAME)
	$(MAKE_LIBFT) fclean
	$(MAKE_LIBMLX) clean
	rm -f $(LIBMLX)

re: fclean all

.PHONY: all fclean re clean
