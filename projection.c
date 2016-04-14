/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 19:46:13 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/14 15:10:28 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

ENV		*iso_conversion(ENV *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->l_nbr)
	{
		j = 0;
		while (j < env->c_nbr)
		{
			env->map[i][j].x = sqrt(2) / 2 * (env->map[i][j].x - env->map[i][j].y);
			env->map[i][j].y = -((sqrt(2) / env->depth * env->map[i][j].z) - (1 / sqrt(6)) *
				(env->map[i][j].x + env->map[i][j].y));
			j++;
		}
		i++;
	}
	return (env);
}

void	z_rotate(ENV *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->l_nbr)
	{
		j = 0;
		while (j < env->c_nbr)
		{
			env->map[i][j].x = cos(env->rotate) * env->map[i][j].x - sin(env->rotate) *
				env->map[i][j].y;
			env->map[i][j].y = sin(env->rotate) * env->map[i][j].x - cos(env->rotate) *
				env->map[i][j].y;
			j++;
		}
		i++;
	}
}
