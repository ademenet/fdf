/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:42:15 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/12 17:49:52 by ademenet         ###   ########.fr       */
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
# include "mlx.h"
# include "libft/libft.h"

# define BUFF_SIZE 100

# define PXL 	t_pxl
# define ENV	t_env

typedef struct s_pxl	t_pxl;
typedef struct s_env	t_env;

struct		s_pxl
{
	double	x;
	double	y;
	double	z;
	char	*color;
};

struct		s_env
{
	void	*mlx;
	void	*win;

	int		l_nbr;
	int		c_nbr;

	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	int		ex;
	int		ey;
	int		dx_c;
	int		dy_c;
	int		x_incr;
	int		y_incr;

	PXL		**map;
};

ENV		parsing(ENV env, char *av);
ENV		iso_conversion(ENV env);
ENV		z_rotate(ENV env);
void	tracing_lines(ENV env);
void	tracing_columns(ENV env);

#endif
