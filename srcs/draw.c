#include "../includes/fractol.h"

void	draw(t_fract *fractal)
{
	int	x;
	int	y;

	x = 0;
	fractal->x = fractal->min.re;
	while (x < MAX_X)
	{
		y = 0;
		fractal->y = fractal->min.im;
		while (y < MAX_Y)
		{
			data_flow(fractal);
			my_mlx_pixel_put(fractal, x, y, fractal->color);
			fractal->y += fractal->y_step;
			y++;
		}
		fractal->x += fractal->x_step;
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}