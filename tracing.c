/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:48:58 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/10 17:05:59 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mlx.h"

typedef struct
{
	void	*mlx_ptr;
	void	*mlx_win;
} data_t;

typedef struct
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	int		ex;
	int		ey;
	int		Dx;
	int		Dy;
	int		x_incr;
	int		y_incr;
} bresenham_t;

/*
** This function is based on Bresenham works.
*/

int		ft_abs(int x)
{
	return (x < 0 ? -x : x);
}

// TODO : finir la structure et les deux cas

void	ft_line_2(bresenham_t trace, data_t data)
{
	int		i;

	i = 0;
	while (i <= trace.Dy)
	{
		mlx_pixel_put(data.mlx_ptr, data.mlx_win, trace.x1, trace.y1, 0x00FFFFFF);
		trace.y1 += trace.y_incr;
		trace.ey -= trace.dx;
		if (trace.ey < 0)
		{
			trace.x1 += trace.x_incr;
			trace.ey += trace.dy;
		}
		i++;
	}
}

void	ft_line_1(bresenham_t trace, data_t data)
{
	int		i;

	i = 0;
	while (i <= trace.Dx)
	{
		mlx_pixel_put(data.mlx_ptr, data.mlx_win, trace.x1, trace.y1, 0x00FFFFFF);
		trace.x1 += trace.x_incr;
		trace.ex -= trace.dy;
		if (trace.ex < 0)
		{
			trace.y1 += trace.y_incr;
			trace.ex += trace.dx;
		}
		i++;
	}
}

void	iniatilizing_bresenham(int x1, int y1, int x2, int y2, data_t data)
{
	bresenham_t		trace;

	trace.x1 = x1;
	trace.y1 = y1;
	trace.x2 = x2;
	trace.y2 = y2;
	trace.ex = abs(x1 - x2);
	trace.ey = abs(y1 - y2);
	trace.dx = 2 * trace.ex;
	trace.dy = 2 * trace.ey;
	trace.Dx = trace.ex;
	trace.Dy = trace.ey;
	trace.x_incr = 1;
	trace.y_incr = 1;
	if (x1 > x2)
		trace.x_incr = -1;
	if (y1 > y2)
		trace.y_incr = -1;
	if (trace.Dx > trace.Dy)
		ft_line_1(trace, data);
	if (trace.Dx < trace.Dy)
		ft_line_2(trace, data);
}


int		main()
{
	data_t	data;

	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
		return (EXIT_FAILURE);
	iniatilizing_bresenham(34, 150, 89, 45, data);
	iniatilizing_bresenham(340, 150, 56, 23, data);
	iniatilizing_bresenham(340, 150, 340, 23, data);
	iniatilizing_bresenham(78, 150, 450, 150, data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
