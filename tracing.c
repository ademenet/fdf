/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:48:58 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/11 16:16:50 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_case_2(TRACE trace, FDF *data)
{
	int		i;

	i = 0;
	while (i <= trace.Dy)
	{
		mlx_pixel_put(data->mlx, data->win, trace.x1, trace.y1, 0x00FFFFFF);
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

static void	ft_case_1(TRACE trace, FDF *data)
{
	int		i;

	i = 0;
	while (i <= trace.Dx)
	{

		mlx_pixel_put(data->mlx, data->win, trace.x1, trace.y1, 0x00FFFFFF);
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

void		iniatilizing_bresenham(ISO pxl_1, ISO pxl_2)
{
	TRACE	trace;
	PXL		*pxl1;
	PXL		*pxl2;

	pxl1 = data->head;
	pxl2 = data->head->prev;
	while (pxl2 != NULL)
	{
		trace.x1 = pxl1->x * 40;
		trace.y1 = pxl1->y * 40;
		trace.x2 = pxl2->x * 40;
		trace.y2 = pxl2->y * 40;
		trace.ex = abs(trace.x1 - trace.x2);
		trace.ey = abs(trace.y1 - trace.y2);
		trace.dx = 2 * trace.ex;
		trace.dy = 2 * trace.ey;
		trace.Dx = trace.ex;
		trace.Dy = trace.ey;
		trace.x_incr = 1;
		trace.y_incr = 1;
		if (pxl1->x > pxl2->x)
			trace.x_incr = -1;
		if (pxl1->y > pxl2->y)
			trace.y_incr = -1;
		if (trace.Dx > trace.Dy)
		{
			ft_case_1(trace, data);
		}
		if (trace.Dx < trace.Dy)
		{
			ft_case_2(trace, data);
		}
		pxl1 = pxl2;
		pxl2 = pxl1->prev;
	}
}
