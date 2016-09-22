
#ifndef JEUDELAVIE_H
#define JEUDELAVIE_H

#include <ctype.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct	s_env
{
	char **map;
	int	winH;
	int	winW;
	int x;
	int y;
}		t_env;

void	initSDL(t_env *env);
void	affichage(t_env *env, SDL_Renderer* Renderer);
void	generation(t_env *env, SDL_Renderer* Renderer);
void	cell(t_env *env);
void	initGrille(t_env *env, SDL_Renderer* Renderer);
void	generation(t_env *env, SDL_Renderer* Renderer);

#endif
