/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:48:58 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/13 18:47:06 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		tracing_display(ENV *env)
{
	env->dx = abs(env->x2 - env->x1);
	env->dy = abs(env->y2 - env->y1);
	env->sx = (env->x1 < env->x2 ? 1 : -1);
	env->sy = (env->y1 < env->y2 ? 1 : -1);
	env->err = (env->dx > env->dy ? env->dx : -(env->dy)) / 2;
	while (!(env->x1 == env->x2 && env->y1 == env->y2))
	{
		mlx_pixel_put(env->mlx, env->win, env->x1, env->y1, 0x00FFFFFF);
		env->e2 = env->err;
		if (env->e2 > -(env->dx))
		{
			env->err -= env->dy;
			env->x1 += env->sx;
		}
		if (env->e2 < env->dy)
		{
			env->err += env->dx;
			env->y1 += env->sy;
		}
	}
}
static void		tracing_lines(ENV *env, int x, int y)
{
	env->x1 = env->map[y][x].x * env->zoom + env->translate_x;
	env->y1 = env->map[y][x].y * env->zoom + env->translate_y;
	env->x2 = env->map[y][x + 1].x * env->zoom + env->translate_x;
	env->y2 = env->map[y][x + 1].y * env->zoom + env->translate_y;
	tracing_display(env);
}

static void		tracing_columns(ENV *env, int x, int y)
{
	env->x1 = env->map[y][x].x * env->zoom + env->translate_x;
	env->y1 = env->map[y][x].y * env->zoom + env->translate_y;
	env->x2 = env->map[y + 1][x].x * env->zoom + env->translate_x;
	env->y2 = env->map[y + 1][x].y * env->zoom + env->translate_y;
	tracing_display(env);
}

void			tracing(ENV *env)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->l_nbr)
	{
		x = 0;
		while (x < env->c_nbr - 1)
		{
			if (y < env->l_nbr - 1)
			{
				tracing_lines(env, x, y);
				tracing_columns(env, x, y);
			}
			else
				tracing_lines(env, x, y);
			x++;
		}
		if (y < env->l_nbr - 1)
			tracing_columns(env, x, y);
		y++;
	}
}
