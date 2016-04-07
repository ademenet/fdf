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

int		get_line(char *argv)
{
	int fd;
	char buf[BUFF_SIZE + 1];
	int lines;

	lines = 0;
	if (!(fd = open(argv, O_RDONLY)))
		return(0);
	while (read(fd, buf, BUFF_SIZE))
	{
		while (*buf == '\n')
			lines++;
	}
	return (lines);
}

int		get_column(char *argv)
{
	int		fd;
	int		column;
	char	*line;

	column = 0;
	if (!(fd = open(argv, O_RDONLY)))
		return(0);
	get_next_line(fd, &line);
	column = ft_count_words(line, ' ');
	return (column);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		lines;
	int		nb_lines_columns[2];

	if (argc == 2)
	{
		nb_lines_columns[0] = get_line(argv[1]);
		nb_lines_columns[1] = get_column(argv[1]);
	}
	printf("line = %d\n colonne = %d\n ", nb_lines_columns[0], nb_lines_columns[1]);
	return (0);
}
