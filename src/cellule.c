#include "jeudelavie.h"

void	modif(t_env *env, int un)
{
	if (un < 2)
		env->map[env->y][env->x] = '0';
	else if ((un == 2 || un == 3) && (env->map[env->y][env->x] == '1' || env->map[env->y][env->x] == '2'))
		env->map[env->y][env->x] = '2';
	else if (un == 3 && env->map[env->y][env->x] == '0')
		env->map[env->y][env->x] = '1';
	else if (un > 3)
		env->map[env->y][env->x] = '0';
	else
		env->map[env->y][env->x] = '0';
}

void	cell(t_env *env)
{
	int un = 0;

	if (env->y == 0 && env->x == 0) {
		if ((env->map[env->y+1][env->x] == '1') || (env->map[env->y+1][env->x] == '2'))
			un++;
		if ((env->map[env->y][env->x+1] == '1') || (env->map[env->y][env->x+1] == '2'))
			un++;
		if ((env->map[env->y+1][env->x+1] == '1') || (env->map[env->y+1][env->x+1] == '2'))

			un++;
	}

	else if (env->y == 0 && env->x == (env->winW-1)) {
		if ((env->map[env->y+1][env->x] == '1') || (env->map[env->y+1][env->x] == '2'))
			un++;
		if ((env->map[env->y][env->x-1] == '1') || (env->map[env->y][env->x-1] == '2'))
			un++;
		if ((env->map[env->y+1][env->x-1] == '1') || (env->map[env->y+1][env->x-1] == '2'))
			un++;
	}

	else if (env->y == 0 && env->x != (env->winW-1) && env->x != 0) {
		if ((env->map[env->y+1][env->x] == '1') || (env->map[env->y+1][env->x] == '2'))
			un++;
		if ((env->map[env->y][env->x+1] == '1') || (env->map[env->y][env->x+1] == '2'))
			un++;
		if ((env->map[env->y+1][env->x+1] == '1') || (env->map[env->y+1][env->x+1] == '2'))
			un++;
		if ((env->map[env->y][env->x-1] == '1') || (env->map[env->y][env->x-1] == '2'))
			un++;
		if ((env->map[env->y+1][env->x-1] == '1') || (env->map[env->y+1][env->x-1] == '2'))
			un++;
	}

	else if (env->x == 0 && env->y != (env->winH-1) && env->y != 0) {
		if ((env->map[env->y-1][env->x] == '1') || (env->map[env->y-1][env->x] == '2'))
			un++;
		if ((env->map[env->y-1][env->x+1] == '1') || (env->map[env->y-1][env->x+1] == '2'))
			un++;
		if ((env->map[env->y][env->x+1] == '1') || (env->map[env->y][env->x+1] == '2'))
			un++;
		if ((env->map[env->y+1][env->x] == '1') || (env->map[env->y+1][env->x] == '2'))
			un++;
		if ((env->map[env->y+1][env->x+1] == '1') || (env->map[env->y+1][env->x+1] == '2'))
			un++;
	}

	else if (env->x == (env->winW-1) && env->y != (env->winH-1) && env->y != 0) {
		if ((env->map[env->y-1][env->x] == '1') || (env->map[env->y-1][env->x] == '2'))
			un++;
		if ((env->map[env->y-1][env->x-1] == '1') || (env->map[env->y-1][env->x-1] == '2'))
			un++;
		if ((env->map[env->y][env->x-1] == '1') || (env->map[env->y][env->x-1] == '2'))
			un++;
		if ((env->map[env->y+1][env->x-1] == '1') || (env->map[env->y+1][env->x-1] == '2'))
			un++;
		if ((env->map[env->y+1][env->x] == '1') || (env->map[env->y+1][env->x] == '2'))
			un++;
	}

	else if (env->y == (env->winH-1) && env->x == 0) {
		if ((env->map[env->y-1][env->x] == '1') || (env->map[env->y-1][env->x] == '2'))
			un++;
		if ((env->map[env->y-1][env->x+1] == '1') || (env->map[env->y-1][env->x+1] == '2'))
			un++;
		if ((env->map[env->y][env->x+1] == '1') || (env->map[env->y][env->x+1] == '2'))
			un++;
	}

	else if (env->y == (env->winH-1) && env->x == (env->winW-1)) {
		if ((env->map[env->y-1][env->x] == '1') || (env->map[env->y-1][env->x] == '2'))
			un++;
		if ((env->map[env->y-1][env->x-1] == '1') || (env->map[env->y-1][env->x-1] == '2'))
			un++;
		if ((env->map[env->y][env->x-1] == '1') || (env->map[env->y][env->x-1] == '2'))
			un++;
	}

	else if (env->y == (env->winH-1) && env->x != (env->winW-1) && env->x != 0) {
		if ((env->map[env->y-1][env->x-1] == '1') || (env->map[env->y-1][env->x-1] == '2'))
			un++;
		if ((env->map[env->y-1][env->x] == '1') || (env->map[env->y-1][env->x] == '2'))
			un++;
		if ((env->map[env->y-1][env->x+1] == '1') || (env->map[env->y-1][env->x+1] == '2'))
			un++;
		if ((env->map[env->y][env->x-1] == '1') || (env->map[env->y][env->x-1] == '2'))
			un++;
		if ((env->map[env->y][env->x+1] == '1') || (env->map[env->y][env->x+1] == '2'))
			un++;
	}

	else {
		if ((env->map[env->y-1][env->x-1] == '1') || (env->map[env->y-1][env->x-1] == '2'))
			un++;
		if ((env->map[env->y-1][env->x] == '1') || (env->map[env->y-1][env->x] == '2'))
			un++;
		if ((env->map[env->y-1][env->x+1] == '1') || (env->map[env->y-1][env->x+1] == '2'))
			un++;
		if ((env->map[env->y][env->x-1] == '1') || (env->map[env->y][env->x-1] == '2'))
			un++;
		if ((env->map[env->y][env->x+1] == '1') || (env->map[env->y][env->x+1] == '2'))
			un++;
		if ((env->map[env->y+1][env->x-1] == '1') || (env->map[env->y+1][env->x-1] == '2'))
			un++;
		if ((env->map[env->y+1][env->x] == '1') || (env->map[env->y+1][env->x] == '2'))
			un++;
		if ((env->map[env->y+1][env->x+1] == '1') || (env->map[env->y+1][env->x+1] == '2'))
			un++;
	}
	modif(env, un);
}