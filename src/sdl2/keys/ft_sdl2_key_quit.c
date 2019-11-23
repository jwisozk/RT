#include "../../../RT.h"

void    ft_sdl2_key_quit(SDL_Event e, int *running)
{
    if((SDL_QUIT == e.type) ||
       (SDL_KEYDOWN == e.type &&
        SDL_SCANCODE_ESCAPE == e.key.keysym.scancode))
        *running = 0;
}
