/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:40:52 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/12 11:15:02 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static ENV		getting_size(ENV env, int fd)
{
	char	**tmp;
	char	*line;
	int		gnl;
	int		i;

	env.l_nbr = 0;
	env.c_nbr = 0;
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		if (env.l_nbr == 0)
		{
			i = 0;
			tmp = ft_strsplit(line, ' ');
			while (tmp[i] != NULL)
			{
				env.c_nbr++;
				i++;
			}
			free(tmp);
		}
		env.l_nbr++;
	}
	return (env);
}

static ENV		getting_content(ENV env, int fd)
{
	char	**tmp;
	char	*line;
	int		i;
	int		j;

	i = 0;
	env.map = (PXL**)malloc(sizeof(PXL*) * env.l_nbr);
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		env.map[i] = (PXL*)malloc(sizeof(PXL) * env.c_nbr);
		j = 0;
		while (tmp[j] != NULL)
		{
			env.map[i][j].x = j + 1;
			env.map[i][j].y = i + 1;
			env.map[i][j].z = ft_atoi(tmp[j]);
			j++;
		}
		i++;
	}
	return (env);
}

ENV				parsing(ENV env, char *av)
{
	int		fd;

	if ((fd = open(av, O_RDONLY)) < 0)
		perror("error: couldn't open file.");
	env = getting_size(env, fd);
	close(fd);
	if ((fd = open(av, O_RDONLY)) < 0)
		perror("error: couldn't open file.");
	env = getting_content(env, fd);
	close(fd);
	return (env);
}
