#include "fdf.h"

void	ft_bresenham(int x1, int y1, int x2, int y2)
{
	float		dx = abs(x2 - x1);
	float		dy = abs(y2 - y1);
	float		m;
	float		e = 0;
	int			x;
	int			y;

	x = x1;
	y = y1;
	m = dx / dy;
	mlx_put_pixel(data.mlx_ptr, data.mlx_win, x, y, 0x00FFFFFF);
	while (x <= x2)
	{
		mlx_put_pixel(data.mlx_ptr, data.mlx_win, x, y, 0x00FFFFFF);
		e -= m;
		if (e < -0.5)
		{
			y--;
			e += 1.0;
		}
		x++;
	}
}
