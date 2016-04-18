/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 19:46:13 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/18 15:17:41 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_bonus_depth(ENV *env)
{
	int		i;
	int		j;

	i = 0;
	while (i < env->l_nbr)
	{
		j = 0;
		while (j < env->c_nbr)
		{
			env->map[i][j].x = sqrt(2) / 2 * (env->map[i][j].x_init -
				env->map[i][j].y_init);
			env->map[i][j].y = -(((sqrt(2) / env->depth) * env->map[i][j].z)
			- (1 / sqrt(6)) * (env->map[i][j].x_init + env->map[i][j].y_init));
			j++;
		}
		i++;
	}
}

void			iso_conversion(ENV *env, int flag)
{
	int		i;
	int		j;

	if (flag == 0)
	{
		i = 0;
		while (i < env->l_nbr)
		{
			j = 0;
			while (j < env->c_nbr)
			{
				env->map[i][j].x = sqrt(2) / 2 * (env->map[i][j].x_init -
					env->map[i][j].y_init);
				env->map[i][j].y = -(((sqrt(2) / env->depth) * env->map[i][j].z)
					- (1 / sqrt(6)) * (env->map[i][j].x_init +
					env->map[i][j].y_init));
				j++;
			}
			i++;
		}
	}
	else
		ft_bonus_depth(env);
}
