/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 19:46:13 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/11 10:12:25 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


u = x*cos(α) + y*cos(α+120°) + z*cos(α-120°)
v = x*sin(α) + y*sin(α+120°) + z*sin(α-120°)

typedef struct	s_iso
{
	int		u;
	int		z;
}				t_iso;

/*
 * t_iso	iso_conversion(PXL *pxl,)
 * {
 * 	int		alpha;
 *
 * 	alpha =
 * 	u = PXL->x * cos(alpha) + PXL->y * cos(alpha + (120 * M_PI / 180)) + PXL->z * cos(alpha - (120 * M_PI / 180);
 * 	v = PXL->x * sin(alpha) + PXL->y * sin(alpha + (120 * M_PI / 180)) + PXL->z * sin(alpha - (120 * M_PI / 180);
 * }
 */

 t_iso		iso_conversion(PXL *pxl)
 {
	t_iso	iso;

	iso->u = sqrt(2) / 2 * (pxl->x - pxl->y);
	iso->v = sqrt(2 / 3) * pxl->z - 1 / sqrt(6) * (pxl->x + pxl->y);
	return (iso);
 }
