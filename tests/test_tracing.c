#include "../fdf.h"

int		main(int ac, char **av)
{
	ENV		env;

	if (ac == 2)
	{
		env = parsing(env, av[1]);
		env.mlx = mlx_init();
		env.win = mlx_new_window(env.mlx, 1366, 768, "FDF");
		iso_conversion(env);
		// z_rotate(env);
		tracing_lines(env);
		tracing_columns(env);
		mlx_loop(env.mlx);
	}
	return (0);
}
