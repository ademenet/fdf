#include "../fdf.h"

int		main(int ac, char **av)
{
	ENV		env;

	if (ac == 2)
	{
		env = parsing(env, av[1]);
		ft_putnbr(env.l_nbr);
		ft_putstr("\n");
		ft_putnbr(env.c_nbr);
		ft_putstr("\n");
		ft_putnbr(env.map[3][2].z);
		ft_putstr("\n");
	}
	return (0);
}
