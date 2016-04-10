/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 19:46:13 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/10 19:51:17 by ademenet         ###   ########.fr       */
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

s_iso	iso_conversion(PXL pxl)
{
	u = PXL->x * cos() + PXL->y * cos() + PXL->z * cos();
	v = PXL->x * sin() + PXL->y * sin() + PXL->z * sin();
}
