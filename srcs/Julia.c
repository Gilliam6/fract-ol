#include "../includes/fractol.h"

void julia(t_fract *fractal)
{
	int x;
	int y;
	int iter;

	fractal->C = init_complex(-0.2, 0.75);
	fractal->x_step = (double)MAX_X / 4.0 / fractal->zoom;
	fractal->y_step = (double)MAX_Y / 4.0 / fractal->zoom;
	x = -MAX_X / 2;

	while(x < MAX_X / 2)
	{
		y = -MAX_Y / 2;
		while(y < MAX_Y / 2)
		{
			fractal->x = (x + fractal->x_move) / fractal->x_step;
			fractal->y = (y + fractal->y_move) / fractal->y_step;
			fractal->Z = init_complex(fractal->x, fractal->y);

			if (fast_check(fractal))
				fractal->color = 0;
			else
			{
				iter = 0;
				while (iter < MAX_ITER && magnitude(fractal->Z) < 4.0)
				{
					fractal->Z = square(fractal->Z);
					fractal->Z = add(fractal->Z, fractal->C);
					iter++;
				}
				fractal->color = colorize(iter, fractal);
			}
			my_mlx_pixel_put(fractal, x + MAX_X / 2, y + MAX_Y / 2,
							 fractal->color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);

}
