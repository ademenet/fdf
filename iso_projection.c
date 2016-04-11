/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 19:46:13 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/11 14:31:22 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct	s_iso
{
	int		u;
	int		z;
}				t_iso;

 t_iso		iso_conversion(PXL *pxl)
 {
	t_iso	iso;

	iso->u = sqrt(2) / 2 * (pxl->x - pxl->y);
	iso->v = sqrt(2 / 3) * pxl->z - 1 / sqrt(6) * (pxl->x + pxl->y);
	return (iso);
 }
