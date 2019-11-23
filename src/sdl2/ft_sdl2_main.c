#include "../../RT.h"

void	ft_print_error(char *msg)
{
    printf("%s\n", msg);
    exit(1);
}

void    ft_sdl2_init(t_sdl *sdl)
{
    sdl->pixels = (int*)malloc(sizeof(int) * SCREEN_SIZE);
    sdl->pitch = SCREEN_WIDTH * 4;
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        ft_print_error(SDL_GetError());
    if (!(sdl->win = SDL_CreateWindow(TITLE_WINDOW, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI)))
        ft_print_error(SDL_GetError());
    if (!(sdl->ren = SDL_CreateRenderer(sdl->win, -1, 0)))
        ft_print_error(SDL_GetError());
    if (!(sdl->tex = SDL_CreateTexture(sdl->ren, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT)))
        ft_print_error(SDL_GetError());
}

void	ft_sdl2_quit(t_sdl *sdl)
{
    SDL_free(sdl->pixels);
    SDL_DestroyTexture(sdl->tex);
    SDL_DestroyRenderer(sdl->ren);
    SDL_DestroyWindow(sdl->win);
    SDL_Quit();
}

void    ft_sdl2_fill_texture(t_sdl *sdl)
{
    int i = 0;
    while (i < SCREEN_SIZE)
    {
        sdl->pixels[i] = 0xFFFF00;
        i++;
    }
}

void    ft_sdl2_render(t_sdl *sdl)
{
    SDL_LockTexture(sdl->tex, NULL, (void *)sdl->pixels, &sdl->pitch);
    ft_sdl2_fill_texture(sdl);
    SDL_UnlockTexture(sdl->tex);
    SDL_UpdateTexture(sdl->tex, NULL, sdl->pixels, sdl->pitch);
    SDL_RenderCopy(sdl->ren, sdl->tex, NULL, NULL);
    SDL_RenderPresent(sdl->ren);
}

void    ft_sdl2_events(SDL_Event e, int *running)
{
    while(SDL_PollEvent(&e))
    {
        ft_sdl2_key_quit(e, running);
    }
}

void    ft_sdl2_loop(t_sdl *sdl)
{
    int     running;

    running = 1;
    while (running)
    {
        ft_sdl2_events(sdl->e, &running);
    }

}

void    ft_sdl2_main(int argc, char **argv)
{
    t_sdl   sdl;

    ft_sdl2_init(&sdl);
    ft_sdl2_render(&sdl);
    ft_sdl2_loop(&sdl);
    ft_sdl2_quit(&sdl);
}