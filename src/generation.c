#include "jeudelavie.h"

void	generation(t_env *env, SDL_Renderer* Renderer)
{
	env->y = 0;
	env->x = 0;

	while (env->y < env->winH)
	{
		while (env->x < env->winW)
		{
			cell(env);
			env->x++;
		}
		env->y++;
		env->x = 0;
	}
}