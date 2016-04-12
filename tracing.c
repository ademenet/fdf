/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:48:58 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/12 16:03:46 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_case_2(ENV env, int x1, int y1, int x2, int y2)
{
	int		i;

	i = 0;
	while (i <= env.dy_c)
	{
		mlx_pixel_put(env.mlx, env.win, x1, y1, 0x00FFFFFF);
		y1 += env.y_incr;
		env.ey -= env.dx;
		if (env.ey < 0)
		{
			x1 += env.x_incr;
			env.ey += env.dy;
		}
		i++;
	}
}

static void	ft_case_1(ENV env, int x1, int y1, int x2, int y2)
{
	int		i;

	i = 0;
	while (i <= env.dx_c)
	{
		mlx_pixel_put(env.mlx, env.win, x1, y1, 0x00FFFFFF);
		x1 += env.x_incr;
		env.ex -= env.dy;
		if (env.ex < 0)
		{
			y1 += env.y_incr;
			env.ex += env.dx;
		}
		i++;
	}
}

static void		iniatilizing_tracing(ENV env, int x1, int y1, int x2, int y2)
{
	env.dx = 2 * env.ex;
	env.dy = 2 * env.ey;
	env.dx_c = env.ex;
	env.dy_c = env.ey;
	if (env.dx_c > env.dy_c)
	{
		ft_case_1(env, x1, y1, x2, y2);
	}
	if (env.dx_c < env.dy_c)
	{
		ft_case_2(env, x1, y1, x2, y2);
	}
}

void		tracing_lines(ENV env)
{
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	y = 0;
	while (y < env.l_nbr)
	{
		x = 0;
		while (x < env.c_nbr - 1)
		{
			x1 = env.map[y][x].x * 40;
			y1 = env.map[y][x].y * 40;
			x2 = env.map[y][x + 1].x * 40;
			y2 = env.map[y][x + 1].y * 40;
			env.ex = abs(x1 - x2);
			env.ey = abs(y1 - y2);
			env.x_incr = 1;
			env.y_incr = 1;
			if (x1 > x2)
				env.x_incr = -1;
			if (y1 > y2)
				env.y_incr = -1;
			iniatilizing_tracing(env, x1, y1, x2, y2);
			x++;
		}
		y++;
	}
}

void		tracing_columns(ENV env)
{
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		x2;
	int		y2;

	y = 0;
	while (y < env.l_nbr - 1)
	{
		x = 0;
		while (x < env.c_nbr)
		{
			x1 = env.map[y][x].x * 40;
			y1 = env.map[y][x].y * 40;
			x2 = env.map[y + 1][x].x * 40;
			y2 = env.map[y + 1][x].y * 40;
			env.ex = abs(x1 - x2);
			env.ey = abs(y1 - y2);
			env.x_incr = 1;
			env.y_incr = 1;
			if (x1 > x2)
				env.x_incr = -1;
			if (y1 > y2)
				env.y_incr = -1;
			iniatilizing_tracing(env, x1, y1, x2, y2);
			x++;
		}
		y++;
	}
}
