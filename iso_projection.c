/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 19:46:13 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/11 16:55:38 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

 pxl		iso_conversion(PXL *pxl)
 {
	pxl->u = sqrt(2) / 2 * (pxl->x - pxl->y);
	pxl->v = sqrt(2 / 3) * pxl->z - 1 / sqrt(6) * (pxl->x + pxl->y);
	return (pxl);
 }
