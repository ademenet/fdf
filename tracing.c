/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:48:58 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/11 10:51:06 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_case_2(TRACE trace, FDF data)
{
	int		i;

	i = 0;
	while (i <= trace.Dy)
	{
		mlx_pixel_put(data.mlx, data.win, trace.x1, trace.y1, 0x00FFFFFF);
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

static void	ft_case_1(TRACE trace, FDF data)
{
	int		i;

	i = 0;
	while (i <= trace.Dx)
	{
		mlx_pixel_put(data.mlx, data.win, trace.x1, trace.y1, 0x00FFFFFF);
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

void		iniatilizing_bresenham(PXL *data)
{
	TRACE	trace;
	PXL		*pxl1;
	PXL		*pxl2;

	while (pxl2 != NULL)
	{
		pxl1 = data;
		pxl2 = data->next;
		trace.x1 = pxl1->x;
		trace.y1 = pxl1->y;
		trace.x2 = pxl2->x;
		trace.y2 = pxl2->y;
		trace.ex = abs(pxl1->x - pxl2->x);
		trace.ey = abs(pxl1->y - pxl2->y);
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
			ft_case_1(trace, data);
		if (trace.Dx < trace.Dy)
			ft_case_2(trace, data);
		pxl1 = pxl2;
		pxl2 = pxl1->next;
	}
}
