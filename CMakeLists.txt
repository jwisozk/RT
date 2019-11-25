cmake_minimum_required(VERSION 3.14)
project(RT C)

find_library(lib/SDL2 lib/SDL2)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wextra")
set(SOURCE_FILES
        lib/libft/ft_atoi.c
        lib/libft/ft_atof.c
        lib/libft/ft_atoi_base.c
        lib/libft/ft_gc.h
        lib/libft/ft_gc.c
        lib/libft/ft_malloc.c
        lib/libft/ft_clean.c
        lib/libft/ft_bzero.c
        lib/libft/ft_del.c
        lib/libft/ft_free_all.c
        lib/libft/ft_isalnum.c
        lib/libft/ft_isalpha.c
        lib/libft/ft_isascii.c
        lib/libft/ft_isdigit.c
        lib/libft/ft_isprint.c
        lib/libft/ft_isspace.c
        lib/libft/ft_itoa.c
        lib/libft/ft_lstadd.c
        lib/libft/ft_lstadd_back.c
        lib/libft/ft_lstdel.c
        lib/libft/ft_lstdelone.c
        lib/libft/ft_lstiter.c
        lib/libft/ft_lstmap.c
        lib/libft/ft_lstnew.c
        lib/libft/ft_memalloc.c
        lib/libft/ft_memccpy.c
        lib/libft/ft_memchr.c
        lib/libft/ft_memcmp.c
        lib/libft/ft_memcpy.c
        lib/libft/ft_memdel.c
        lib/libft/ft_memmove.c
        lib/libft/ft_memset.c
        lib/libft/ft_putchar.c
        lib/libft/ft_putchar_fd.c
        lib/libft/ft_putendl.c
        lib/libft/ft_putendl_fd.c
        lib/libft/ft_putnbr.c
        lib/libft/ft_putnbr_fd.c
        lib/libft/ft_putstr.c
        lib/libft/ft_putstr_fd.c
        lib/libft/ft_strcat.c
        lib/libft/ft_strchr.c
        lib/libft/ft_strclr.c
        lib/libft/ft_strcmp.c
        lib/libft/ft_strcpy.c
        lib/libft/ft_strdel.c
        lib/libft/ft_strdup.c
        lib/libft/ft_strequ.c
        lib/libft/ft_striter.c
        lib/libft/ft_striteri.c
        lib/libft/ft_strjoin.c
        lib/libft/ft_strlcat.c
        lib/libft/ft_strlen.c
        lib/libft/ft_strmap.c
        lib/libft/ft_strmapi.c
        lib/libft/ft_strncat.c
        lib/libft/ft_strncmp.c
        lib/libft/ft_strncpy.c
        lib/libft/ft_strnequ.c
        lib/libft/ft_strnew.c
        lib/libft/ft_strnstr.c
        lib/libft/ft_strrchr.c
        lib/libft/ft_strrev.c
        lib/libft/ft_strsplit.c
        lib/libft/ft_strstr.c
        lib/libft/ft_strsub.c
        lib/libft/ft_strtrim.c
        lib/libft/ft_tolower.c
        lib/libft/ft_toupper.c
        lib/libft/get_next_line.c
        lib/libft/libft.h
        lib/libft/ft_print.c
        src/main.c
        src/RT.h
        src/RTv1.h
        src/camera.c
        src/camera_create.c
        src/camera_update.c
        src/camera_validate.c
        src/color.c
        src/draw.c
        src/etc_1.c
        src/etc_2.c
        src/geometric_create.c
        src/light_create.c
        src/light_update.c
        src/light_validate.c
        src/lighting.c
        src/objects_calculate.c
        src/objects_create.c
        src/objects_fill.c
        src/objects_intersect.c
        src/objects_update.c
        src/objects_update_min.c
        src/objects_validate.c
        src/operations_d.c
        src/operations_v.c
        src/scene_extra.c
        src/scene_get.c
        src/transform.c
        src/sdl2/ft_sdl2_main.c
        src/sdl2/keys/ft_sdl2_key_quit.c)
#set(SOURCE_FILES src/main.c src/sdl2/ft_sdl2_main.c src/sdl2/keys/ft_sdl2_key_quit.c)
add_executable(RT ${SOURCE_FILES})
target_link_libraries(RT ${SDL2})



#add_executable(RTv1 ${SOURCE_FILES})
#target_link_libraries(RTv1 ${LIBMLX} ${OPENGL} ${APPKIT})
