/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:48:58 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/09 19:01:46 by ademenet         ###   ########.fr       */
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
	int		dx;
	int		dy;
	int		ex;
	int		ey;
	int		x_incr;
	int		y_incr;
	int		i;
	int		Dx;
	int		Dy;
} t_bresenham;

/*
** This function is based on Bresenham works.
*/

int		ft_abs(int x)
{
	return (x < 0 ? -x : x);
}

// TODO : finir la structure et les deux cas

void	line(int x1, int y1, int x2, int y2, data_t data)
{
	int		dx;
	int		dy;
	int		e;
	int		x_incr;
	int		y_incr;
	int		i;
	int		Dx;
	int		Dy;

	e = ft_abs(x2 - x1);
	dx = 2 * e;
	dy = 2 * ft_abs(y2 - y1);
	Dx = ex;
	if (x1 > x2)
		x_incr = -1;
	if (y1 > y2)
		y_incr = -1;
	if (Dx > Dy)
	{
		while (i <= Dx)
		{
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, x1, y1, 0x00FFFFFF);
			x1 += x_incr
			ex -= dy;
			if (e < 0)
			{
				y1 += y_incr;
				e += dx;
			}
			i++;
		}
	}
	if (Dx < Dy)
	{
		while (i <= Dy)
		{
			mlx_pixel_put(data.mlx_ptr, data.mlx_win, x1, y1, 0x00FFFFFF);
			y1 += y_incr;
			ey -= dx;
			if (ey < 0)
			{
				x1 += x_incr;
				ey += dy;
			}
			i++;
		}
	}
}



int		main()
{
	data_t	data;

	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
		return (EXIT_FAILURE);
	line(34, 150, 89, 45, data);
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
