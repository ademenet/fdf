/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 10:13:25 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/14 10:53:42 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_binding(int keycode, ENV *env)
{
	int		i;

	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		i = -1;
		while (++i < env->l_nbr) // Probleme de free abort
			free(env->map[i]);
		free(env->map);
		free(env);
		exit(0);
	}
	if (keycode == 123)
	{
		env->translate_x -= 5;
	}
	if (keycode == 124)
	{
		env->translate_x += 5;
	}
	if (keycode == 125)
	{
		env->translate_y += 5;
	}
	if (keycode == 126)
	{
		env->translate_y -= 5;
	}
	if (keycode == 78)
	{
		env->zoom += 5;
	}
	if (keycode == 69)
	{
		env->zoom -= 5;
	}
	if (keycode == 15)
	{
		env->rotate += 5;
		z_rotate(env);
	}
	mlx_clear_window(env->mlx, env->win);
	tracing(env);

	return(0);
}
