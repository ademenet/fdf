/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:14:41 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/11 10:20:03 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		fdf->win = mlx_new_window(fdf->mlx, 1366, 768, "FDF by ademenet");
		fdf = iniatilizing_bresenham(fdf);
		mlx_loop(fdf->mlx);
	}
	return (0);
}

/*
 * int		main()
 * {
 * 	data_t	data;
 *
 * 	if ((data.mlx_ptr = mlx_init()) == NULL)
 * 		return (EXIT_FAILURE);
 * 	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
 * 		return (EXIT_FAILURE);
 * 	iniatilizing_bresenham(34, 150, 89, 45, data);
 * 	iniatilizing_bresenham(340, 150, 56, 23, data);
 * 	iniatilizing_bresenham(340, 150, 340, 23, data);
 * 	iniatilizing_bresenham(78, 150, 450, 150, data);
 * 	mlx_loop(data.mlx_ptr);
 * 	return (EXIT_SUCCESS);
 * }
 */

/*
 * int		main(int argc, char **argv)
 * {
 * 	int		fd;
 * 	int		lines;
 * 	int		nb_lines_columns[2];
 *
 * 	if (argc == 2)
 * 	{
 * 		nb_lines_columns[0] = get_line(argv[1]);
 * 		nb_lines_columns[1] = get_column(argv[1]);
 * 	}
 * 	printf("line = %d\n colonne = %d\n ", nb_lines_columns[0], nb_lines_columns[1]);
 * 	return (0);
 * }
 */
