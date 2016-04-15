/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:14:41 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/15 18:13:13 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			tracing_initialize(ENV *env)
{
	int		x_max;
	int		y_max;

	env->zoom = 1;
	env->depth = 5;
	env->translate_x = 150;
	env->translate_y = 150;
	env->win_x = 1280;
	env->win_y = 1024;
	x_max = env->map[env->l_nbr - 1][env->c_nbr - 1].x;
	y_max = env->map[env->l_nbr - 1][env->c_nbr - 1].y;
	while ((x_max * env->zoom + env->translate_x)
			< (env->win_x - env->translate_x)
	  	&& (y_max * env->zoom + env->translate_x)
			< (env->win_y - env->translate_y))
		env->zoom += 1;
}

void	init_img(ENV *env)
{
	if ((env->mlx = mlx_init()) == NULL)
		ft_error("mlx_init failed");
	if ((env->win = mlx_new_window(env->mlx,
		env->win_x, env->win_y, "FDF")) == NULL)
		ft_error("mlx_new_window failed");
	env->img = mlx_new_image(env->mlx, env->win_x, env->win_y);
	env->img_data = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->endian);
}

int		main(int ac, char **av)
{
	ENV		env;

	if (ac == 2)
	{
		parsing(&env, av[1]);
		tracing_initialize(&env);
		init_img(&env);
		iso_conversion(&env);
		tracing(&env);
		display_menu(&env);
		mlx_put_image_to_window(env.mlx, env.win, env.img, 0, 0);
		mlx_hook(env.win, 2,1, &key_binding, &env);
		mlx_loop(env.mlx);
	}
	else
		ft_error("wrong number of arguments. Please precise only one file");
	return (0);
}
