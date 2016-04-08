/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:48:58 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/08 16:11:24 by ademenet         ###   ########.fr       */
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

/*
 ** This function is based on Bresenham works.
 */

int		abs(int x)
{
	return (x < 0 ? -x : x);
}

void	line(int x1, int y1, int x2, int y2, data_t data)
{
	int		dx;
	int		dy;
	int		e;

	e = abs(x2 - x1);
	dx = 2 * e;
	dy = 2 * abs(y2 - y1);
	while (x1 <= x2)
	{
		mlx_pixel_put(data.mlx_ptr, data.mlx_win, x1, y1, 0x00FFFFFF);
		x1++;
		e-=dy;
		if (e < 0)
		{
			y1--;
			e+=dx;
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
