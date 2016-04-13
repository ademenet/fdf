/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 10:13:25 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/13 14:07:54 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_binding(int keycode, ENV *env)
{
	int		i;

	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		i = 0;
		while (i++ < env->l_nbr)
			free(env->map[i]);
		free(env->map);
		free(env);
		exit(0);
	}
	if (keycode == 123)
	{
		env->rotate = M_PI / 36;
		z_rotate(env);
	}
	return(0);
}
