/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 17:55:48 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/11 16:54:44 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

PXL			*ft_create_pxl(FDF *fdf, int pxl_info[3])
{
	PXL *new;

	if (!(new = (PXL*)malloc(sizeof(PXL))))
		return (NULL);
	new->x = pxl_info[0];
	new->y = pxl_info[1];
	new->z = pxl_info[2];
	new->u = 0;
	new->v = 0;
	new->color = "0xFFFFFF";
	new->next = NULL;
	new->prev = fdf->head;
	return (new);
}

FDF			*ft_create_fdf(void)
{
	FDF		*new;
	int		pxl_info[3];
	char	*color;

	color = "0x000000";
	pxl_info[0] = 0;
	pxl_info[1] = 0;
	pxl_info[2] = 0;
	if (!(new = (FDF*)malloc(sizeof(FDF))))
		return (NULL);
	new->win = NULL;
	new->mlx = NULL;
	new->head = ft_create_pxl(new, pxl_info);
	return (new);
}

PXL			*ft_add_pxl(FDF *fdf, int pxl_info[3])
{
	PXL *tmp;

	if (!(fdf->head))
		return (fdf->head = ft_create_pxl(fdf, pxl_info));
	tmp = fdf->head;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->next = ft_create_pxl(fdf, pxl_info));
}

void		ft_destroy_struct(FDF *fdf)
{
	while (fdf->head->next)
	{
		free(fdf->head);
		fdf->head = fdf->head->next;
	}
	while (fdf->head->prev)
	{
		free(fdf->head);
		fdf->head = fdf->head->prev;
	}
	free(fdf);
}
