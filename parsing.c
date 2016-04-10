/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:40:52 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/10 18:31:09 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static FDF		*ft_fill_struct_pxl(FDF *fdf, int fd)
{
	char		*line;
	int			pxl_info[3];
	char		**tmp;
	char		**tmp2;
	char		*color;

	pxl_info[0] = 0;
	pxl_info[1] = 0;
	while ((pxl_info[0] = get_next_line(fd, &line)))
	{
		tmp = ft_strsplit(line, ' ');
		while (tmp[pxl_info[0]])
		{
			if (ft_strrchr(*tmp, ',') != NULL && tmp2 == ft_strsplit(*tmp, ','))
			{
				pxl_info[2] = ft_atoi(tmp2[0]);
				color = tmp2[1];
			}
			pxl_info[2] = ft_atoi(tmp[pxl_info[0]]);
			fdf->head = ft_add_pxl(fdf, pxl_info);
			pxl_info[0]++;
		}
		pxl_info[1]++;
	}
	return (fdf);
}

FDF				*ft_print_pxl(FDF *fdf)
{
	int space;

	space = 10;
	while (fdf->head->prev)
	{
		if (fdf->head->z == 0)
			mlx_pixel_put(fdf->mlx, fdf->win, (fdf->head->x * space),
				(fdf->head->y * space), 0xFFFFFF);
		else
			mlx_pixel_put(fdf->mlx, fdf->win, (fdf->head->x * space),
				(fdf->head->y * space), 0x0000FF);
		fdf->head = fdf->head->prev;
	}
	return (fdf);
}

int				main(int ac, char **av)
{
	FDF			*fdf;
	int			fd;

	if (ac >= 2)
	{
		fd = open(av[1], O_RDONLY);
		fdf = ft_create_fdf();
		fdf->head->prev = NULL;
		fdf = ft_fill_struct_pxl(fdf, fd);
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, 1000, 1000, "FDF");
		fdf = ft_print_pxl(fdf);
		mlx_loop(fdf->mlx);
	}
	return (0);
}
