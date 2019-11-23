/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RT.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:59:55 by jwisozk           #+#    #+#             */
/*   Updated: 2019/11/23 22:42:27 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <SDL2/SDL.h>
# include <stdio.h>

# define SCREEN_WIDTH	    601
# define SCREEN_HEIGHT      601
# define SCREEN_SIZE        (SCREEN_WIDTH * SCREEN_HEIGHT)
# define TITLE_WINDOW       "R4Y7r4c1N9_C4P031R4_CR3W"

typedef struct              s_sdl
{
    SDL_Window              *win;
    SDL_Renderer            *ren;
    SDL_Texture	            *tex;
    SDL_Event               e;
    int                     *pixels;
    int                     pitch;
}                           t_sdl;

void    ft_sdl2_main(int argc, char **argv);

void    ft_sdl2_key_quit(SDL_Event e, int *running);

#endif