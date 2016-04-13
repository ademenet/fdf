/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:14:41 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/13 09:22:10 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	ENV		env;

	if (ac == 2)
	{
		env = parsing(env, av[1]);
		env.mlx = mlx_init();
		env.win = mlx_new_window(env.mlx, 1366, 768, "FDF");
		z_rotate(env);
		iso_conversion(env);
		tracing_lines(env);
		tracing_columns(env);
		mlx_loop(env.mlx);
	}
	return (0);
}
