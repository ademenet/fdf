/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:14:41 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/14 17:52:07 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	ENV		*env;

	if (ac == 2)
	{
		if ((env = (ENV*)malloc(sizeof(ENV))) == NULL)
			ft_error("malloc failed");
		parsing(env, av[1]);
		tracing_initialize(env);
		if ((env->mlx = mlx_init()) == NULL)
			ft_error("mlx_init failed");
		if ((env->win = mlx_new_window(env->mlx,
			env->win_x, env->win_y, "FDF")) == NULL)
			ft_error("mlx_new_window failed");
		iso_conversion(env);
		tracing(env);
		env->img = mlx_new_image(env->mlx, env->win_x, env->win_y);
		mlx_get_data_addr(env->mlx, int *bits_per_pixel, int *size_line, int *endian);
		mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
		mlx_hook(env->win, 2,1, &key_binding, env);
		mlx_loop(env->mlx);
	}
	else if (ac > 2)
		ft_error("too much file arguments. Please precise only one file");
	else
		ft_error("not enough file arguments. Please precise at least one file");
	return (0);
}
