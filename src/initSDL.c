#include "jeudelavie.h"

void	sdlExit(SDL_Window* Window, SDL_Renderer* Renderer)
{
	if (Renderer)
		SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
    SDL_Quit();
    exit(0);
}

void	initSDL(t_env *env)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		printf("SDL_Init failed: %s\n", SDL_GetError());
		exit(-1);
	}

	SDL_Window* Window = NULL;
	SDL_Renderer* Renderer = NULL;

	if (!(Window = SDL_CreateWindow("Jeu de la Vie", SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, env->winW, env->winH, SDL_WINDOW_SHOWN))) {
		printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
		SDL_Quit();
	}

	if (!(Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED))) {
		printf("SDL_CreateRenderer failed: %s\n", SDL_GetError());
		sdlExit(Window, NULL);
	}

	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
	SDL_RenderClear(Renderer);
	SDL_RenderPresent(Renderer);

	initGrille(env, Renderer);

	while (42)
	{
//		pid_t pid = fork();

//		if (pid == 0){
		affichage(env, Renderer);
//			exit(0);
//		}
		generation(env, Renderer);
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
		    switch(event.type) {
		        case SDL_QUIT: // Clic sur la croix
		            sdlExit(Window, Renderer);
		        case SDL_KEYUP: // Relâchement d'une touche
		            if ( event.key.keysym.sym == SDLK_ESCAPE)
		            	sdlExit(Window, Renderer);
		    }
		}
//		waitpid(pid, NULL, 0);
	}
}