#include "jeudelavie.h"

t_env	*initVar(char **argv, t_env *env)
{
	env->winH = atoi(argv[1]);
	env->winW = atoi(argv[2]);

	return (env);
}

int isdigit_char(char *str)
{
	while (*str)
	{
		if ((*str > '9') || (*str < '0'))
			return (0);
		str++;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_env env;

	if (argc == 3 && isdigit_char(argv[1]) && isdigit_char(argv[2]) &&
		initVar(argv, &env) && env.winH <= 1200 && env.winW <= 1900 && env.winH >= 100 && env.winW >= 100)
		initSDL(&env);
	else
		printf(" Usage : [%s] [hauteur min:100 max:1200] [largeur min:100 max:1900]\n", argv[0]);
	return (0);
}
