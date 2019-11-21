#include "RT.h"

const int WIDTH = 800, HEIGHT = 600;
void	ft_print_error(char *msg)
{
	printf("%s\n", msg);
	exit(1);
}

SDL_Surface *ft_init(SDL_Window **window)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		ft_print_error("Error");

	int flags = IMG_INIT_PNG;
	if ( !( IMG_Init( flags ) & flags ) ) {
		ft_print_error("Error");
	}

	if (!(*window = SDL_CreateWindow("R4Y7r4c1N9_C4P031R4_CR3W",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI)))
		ft_print_error("Error");
	return(SDL_GetWindowSurface(*window));
}

//int ft_load(SDL_Surface **john) {
//	*john = SDL_LoadBMP("/Users/iplastun/CLionProjects/RT/john.bmp");
//
//	return 0;
//}
int ft_load(SDL_Surface **flower, SDL_Surface* screen) {
	*flower= IMG_Load("/Users/iplastun/CLionProjects/RT/rt8.png");
	*flower = SDL_ConvertSurface(*flower, screen->format, 0);
	return 0;
}

void	ft_quit(SDL_Surface* screen, SDL_Surface* flower, SDL_Window **window)
{
	SDL_FreeSurface(flower);
	SDL_FreeSurface(screen);
	SDL_DestroyWindow(*window);
	SDL_Quit();
	IMG_Quit();
}

int main(void)
{
	int running;
	SDL_Window *window;
	SDL_Surface* screen;
//	SDL_Surface *john = NULL;
	SDL_Surface *flower = NULL;
	SDL_Event e;

//	SDL_Rect r;
//	int x = 0;
//	int y = 0;
//	r.x = x;
//	r.y = y;
	SDL_Rect bg_flower;
	bg_flower.w = WIDTH;
	bg_flower.h = HEIGHT;
	bg_flower.x = 0;
	bg_flower.y = 0;

	running = 1;
	screen = ft_init(&window);

//	if (ft_load(&john) == 1) {
//		return 1;
//	}
	if (ft_load(&flower, screen) == 1) {
		return 1;
	}
	while (running)
	{
		while(SDL_PollEvent(&e))
		{
			if((SDL_QUIT == e.type) ||
			   (SDL_KEYDOWN == e.type &&
				SDL_SCANCODE_ESCAPE == e.key.keysym.scancode))
				running = 0;
		}

//		if (e.type == SDL_KEYDOWN) {
//			if (e.key.keysym.sym == SDLK_UP) {
//				y -= 1;
//			}
//			if (e.key.keysym.sym == SDLK_DOWN) {
//				y += 1;
//			}
//			if (e.key.keysym.sym == SDLK_RIGHT) {
//				x += 1;
//			}
//			if (e.key.keysym.sym == SDLK_LEFT) {
//				x -= 1;
//			}
//		}
//		r.x = x;
//		r.y = y;
		SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 0));
//		SDL_BlitSurface(john, NULL, screen, &r);
		SDL_BlitScaled(flower, NULL, screen, &bg_flower);
		SDL_UpdateWindowSurface(window);
	}
	ft_quit(screen, flower, &window);
	return (0);
}