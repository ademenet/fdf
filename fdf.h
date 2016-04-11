/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ademenet <ademenet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 17:42:15 by ademenet          #+#    #+#             */
/*   Updated: 2016/04/11 13:13:36 by ademenet         ###   ########.fr       */
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
# define FDF	t_fdf
# define TRACE	t_bresenham

typedef struct s_pxl 		t_pxl;
typedef struct s_fdf		t_fdf;
typedef struct s_bresenham	t_bresenham;

struct 		s_pxl
{
	int 	x;
	int 	y;
	int 	z;
	char	*color;
	PXL 	*next;
	PXL 	*prev;
};

struct 		s_fdf
{
	void 	*mlx;
	void	*win;
	PXL 	*head;
};

struct		s_bresenham
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		dx;
	int		dy;
	int		ex;
	int		ey;
	int		Dx;
	int		Dy;
	int		x_incr;
	int		y_incr;
};

FDF			*ft_fill_struct_pxl(FDF *fdf, int fd);
PXL			*ft_create_pxl(FDF *fdf, int pxl_info[3]);
FDF			*ft_create_fdf(void);
PXL			*ft_add_pxl(FDF *fdf, int pxl_info[3]);
void		ft_destroy_struct(FDF *fdf);
void		iniatilizing_bresenham(FDF *data);

#endif
