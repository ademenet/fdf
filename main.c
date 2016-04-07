/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:14:41 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/06 19:30:22 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		gnl;
	char	*line[100];
	COORD	*pixels;

	if (argc == 2)
	{
		gnl = pixels_tab_allocate(argv[1], pixels);
		printf("nbr pxl : %d\n", gnl);
	}
	return (0);
}
