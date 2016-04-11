/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:40:52 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/11 19:14:10 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
 * void	parsing(char *av)
 * {
 *
 * }
 */

void 	counting_lines_and_columns(ENV env, char *av)
{
	// char	**tmp;
	char	*line;
	int		fd;

	env.l_nbr = 0;
	env.c_nbr = 0;
	if ((fd = open(av, O_RDONLY)) < 0)
		perror("Couldn't open file.");
	while (get_next_line(fd, &line) > 0)
	{
		/*
		 * tmp = ft_strsplit(line, ' ');
		 * while (tmp == NULL)
		 * {
		 * 	env.c_nbr++;
		 * 	tmp++;
		 * }
		 * free(tmp);
		 */
		env.l_nbr++;
	}
	close(fd);
}

int		main(int ac, char **av)
{
	ENV		env;

	if (ac == 2)
	{
		counting_lines_and_columns(env, av[1]);
		printf("line %d\ncol %d\n", env.l_nbr, env.c_nbr);
	}
	return (0);
}

/*
 * PXL		*ft_fill_struct_pxl(FDF *fdf, int fd)
 * {
 * 	char		*line;
 * 	int			pxl_info[3];
 * 	char		**tmp;
 * 	char		**tmp2 = NULL;
 * 	char		*color;
 *
 * 	pxl_info[0] = 0;
 * 	pxl_info[1] = 0;
 * 	while ((pxl_info[0] = get_next_line(fd, &line)))
 * 	{
 * 		tmp = ft_strsplit(line, ' ');
 * 		while (tmp[pxl_info[0]])
 * 		{
 * 			if (ft_strrchr(*tmp, ',') != NULL && tmp2 == ft_strsplit(*tmp, ','))
 * 			{
 * 				pxl_info[2] = ft_atoi(tmp2[0]);
 * 				color = tmp2[1];
 * 			}
 * 			pxl_info[2] = ft_atoi(tmp[pxl_info[0]]);
 * 			fdf->head = ft_add_pxl(fdf, pxl_info);
 * 			pxl_info[0]++;
 * 		}
 * 		pxl_info[1]++;
 * 	}
 * 	return (fdf);
 * }
 *
 * FDF				*ft_print_pxl(FDF *fdf)
 * {
 * 	int		space;
 * 	PXL		**pixels;
 *
 * 	space = 10;
 * 	while (fdf->head->prev)
 * 	{
 * 		if (fdf->head->z == 0)
 * 			mlx_pixel_put(fdf->mlx, fdf->win, (fdf->head->x * space),
 * 				(fdf->head->y * space), 0xFFFFFF);
 * 		else
 * 			mlx_pixel_put(fdf->mlx, fdf->win, (fdf->head->x * space),
 * 				(fdf->head->y * space), 0x0000FF);
 * 		fdf->head = fdf->head->prev;
 * 	}
 * 	return (fdf);
 * }
 */
