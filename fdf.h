/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:42:15 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/18 14:48:21 by ademenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include "mlx.h"
# include "libft/libft.h"

# define RGB(r, g, b)(256 * 256 * (int)(r) + 256 * (int)(g) + (int)(b))
# define PXL		t_pxl
# define ENV		t_env

# define INT_MAX	2147483647
# define INT_MIN	-2147483648

typedef struct s_pxl	t_pxl;
typedef struct s_env	t_env;

struct		s_pxl
{
	double	x_init;
	double	y_init;
	double	x;
	double	y;
	double	z;
	char	*color;
};

struct		s_env
{
	void	*mlx;
	void	*win;

	int		win_x;
	int		win_y;

	int		l_nbr;
	int		c_nbr;

	int		rotate;
	int		zoom;
	int		depth;
	int		translate_x;
	int		translate_y;
	int		x_ori;
	int		y_ori;

	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		e2;
	PXL		**map;
};

void		parsing(ENV *env, char *av);
void		iso_conversion(ENV *env, int flag);
void		tracing_initialize(ENV *env);
void		tracing(ENV *env);
int			key_binding(int keycode, ENV *env);
void		ft_error(char *s);
void		display_menu(ENV *env);

#endif
