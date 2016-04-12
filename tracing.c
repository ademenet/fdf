/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:48:58 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/12 13:42:30 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_case_2(ENV env)
{
	int		i;

	i = 0;
	while (i <= env.dy_c)
	{
		mlx_pixel_put(data->mlx, data->win, env.x1, env.y1, 0x00FFFFFF);
		env.y1 += env.y_incr;
		env.ey -= env.dx;
		if (env.ey < 0)
		{
			env.x1 += env.x_incr;
			env.ey += env.dy;
		}
		i++;
	}
}

static void	ft_case_1(ENV env)
{
	int		i;

	i = 0;
	while (i <= env.dx_c)
	{
		mlx_pixel_put(env.mlx, env.win, env.map[y][x].x, env.map[y][x].y, 0x00FFFFFF);
		env.map[y][x].x += env.x_incr;
		env.ex -= env.dy;
		if (env.ex < 0)
		{
			env.map[y][x].y += env.y_incr;
			env.ex += env.dx;
		}
		i++;
	}
}

void		iniatilizing_tracing(ENV env)
{
	env.ex = abs(env.map[y][x].x - env.map[y][x + 1].x);
	env.ey = abs(env.map[y][x].y - env.map[y][x + 1].y);
	env.dx = 2 * env.ex;
	env.dy = 2 * env.ey;
	env.dx_c = env.ex;
	env.dy_c = env.ey;
	env.x_incr = 1;
	env.y_incr = 1;
	if (env.map[y][x].x > env.map[y][x + 1].x)
		env.x_incr = -1;
	if (env.map[y][x].y > env.map[y][x + 1].y)
		env.y_incr = -1;
	if (env.dx_c > env.dy_c)
	{
		ft_case_1(env, int x, int y);
	}
	if (env.dx_c < env.dy_c)
	{
		ft_case_2(env, int x, int y);
	}
}

void		tracing_lines(ENV env)
{
	int		x;
	int		y;

	y = 0;
	while (y < env.l_nbr)
	{
		x = 0;
		while (x < env.c_nbr - 1)
		{
			
			x++;
		}
		y++;
	}
}
