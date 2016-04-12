/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 19:46:13 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/12 17:58:42 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

ENV		iso_conversion(ENV env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env.l_nbr)
	{
		j = 0;
		while (j < env.c_nbr)
		{
			/*
			 * env.map[i][j].x = env.map[i][j].x * cos(M_PI_4) + env.map[i][j].y *
			 * 	cos(M_PI_4 + (2 / 3 * M_PI)) + env.map[i][j].z * cos(M_PI_4 -
			 * 	(2 / 3 * M_PI));
			 * env.map[i][j].y = env.map[i][j].x * sin(M_PI_4) + env.map[i][j].y *
			 * 	sin(M_PI_4 + (2 / 3 * M_PI)) + env.map[i][j].z * sin(M_PI_4 -
			 * 	(2 / 3 * M_PI));
			 */
			env.map[i][j].x = (env.map[i][j].x - env.map[i][j].z) / sqrt(2);
			env.map[i][j].y = (env.map[i][j].x + 2 * env.map[i][j].y + env.map[i][j].z) / sqrt(6);
			j++;
		}
		i++;
	}
	return (env);
}

ENV		z_rotate(ENV env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env.l_nbr)
	{
		j = 0;
		while (j < env.c_nbr)
		{
			env.map[i][j].x = cos(M_PI_4) * env.map[i][j].x - sin(M_PI_4) * env.map[i][j].y;
			env.map[i][j].y = sin(M_PI_4) * env.map[i][j].x - cos(M_PI_4) * env.map[i][j].y;
			j++;
		}
		i++;
	}
	return (env);

}
