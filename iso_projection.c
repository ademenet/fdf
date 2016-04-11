/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 19:46:13 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/11 09:26:09 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


u = x*cos(α) + y*cos(α+120°) + z*cos(α-120°)
v = x*sin(α) + y*sin(α+120°) + z*sin(α-120°)

struct	s_iso
{
	int		u;
	int		z;
};

s_iso	iso_conversion(PXL *pxl)
{
	u = PXL->x * cos(M_PI4) + PXL->y * cos(M_PI4) + PXL->z * cos(M_PI4);
	v = PXL->x * sin(M_PI4) + PXL->y * sin(M_PI4) + PXL->z * sin(M_PI4);
}
