/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/10 19:46:13 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/18 15:35:15 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			iso_conversion(ENV *env)
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
				- (1 / sqrt(6)) * (env->map[i][j].x_init +
				env->map[i][j].y_init));
			j++;
		}
		i++;
	}
}
