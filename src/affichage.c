#include "jeudelavie.h"

void	misAzero(t_env *env)
{
	int y = 0, x = 0;

	env->map = (char**)malloc(sizeof(char*) * env->winH + 1);
	while (y <= env->winH)
		env->map[y++] = (char*)malloc(sizeof(char) * env->winW + 1);
	y = 0;
	while (y < env->winH)
	{
		while (x < env->winW)
		{
			env->map[y][x] = '0';
			x++;
		}
		y++;
		x = 0;
	}
}

void	initGrille(t_env *env, SDL_Renderer* Renderer)
{
	unsigned long limitr = (env->winH * env->winW) / 15;
	unsigned long randX, randY;
	srand(time(NULL));

	misAzero(env);

	while (limitr > 0)
	{
		randY = (rand() % (env->winH-1)) + 1;
		randX = (rand() % (env->winW-1)) + 1;
		env->map[randY][randX] = '1';
		limitr--;
	}
}

void	affichage(t_env *env, SDL_Renderer* Renderer)
{
	int y = 0, x = 0;

	while (y < env->winH)
	{
		while (x < env->winW)
		{
			if ((env->map[y][x] == '1') || (env->map[y][x] == '2')) {
				SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
				SDL_RenderDrawPoint(Renderer, x, y);
			}
				
			else {
				SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 255);
				SDL_RenderDrawPoint(Renderer, x, y);	
			}
			x++;
		}
		y++;
		x = 0;
	}
	SDL_RenderPresent(Renderer);
}