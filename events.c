/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 10:13:25 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/18 13:58:20 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		translation(int keycode, ENV *env)
{
	if (keycode == 123)
		env->translate_x -= 5;
	if (keycode == 124)
		env->translate_x += 5;
	if (keycode == 126)
		env->translate_y += 5;
	if (keycode == 125)
		env->translate_y -= 5;
}

static void		zoom(int keycode, ENV *env)
{
	if (keycode == 78)
	{
		if (env->zoom > 1)
			env->zoom -= 5;
		else
			env->zoom = 1;
	}
	if (keycode == 69)
		env->zoom += 5;
}

int				key_binding(int keycode, ENV *env)
{
	int		i;

	if (keycode == 53)
	{
		mlx_destroy_window(env->mlx, env->win);
		i = -1;
		while (++i < env->l_nbr)
			free(env->map[i]);
		free(env->map);
		free(env);
		exit(0);
	}
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
		translation(keycode, env);
	if (keycode == 78 || keycode == 69)
		zoom(keycode, env);
	mlx_clear_window(env->mlx, env->win);
	display_menu(env);
	tracing(env);
	return (0);
}

void			display_menu(ENV *env)
{
	mlx_string_put(env->mlx, env->win, 20, 20, 0x00BFA5,
		"fleche directionelle pour deplacer la camera");
	mlx_string_put(env->mlx, env->win, 20, 40, 0x00B8D4,
		"[+] et [-] sur le pave numerique pour zoomer");
	mlx_string_put(env->mlx, env->win, 20, 60, 0x0091EA,
		"ESC pour quitter");
}
