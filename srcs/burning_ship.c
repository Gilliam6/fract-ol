#include "../includes/fractol.h"

void burning_ship(t_fract *fractal)
{
	int x;
	int y;
	int iter;
	int P_x;
	int P_y;

	P_x = MAX_X / 2;
	P_y = MAX_Y / 2;
	fractal->x_step = (double)P_x / 2.0 / fractal->zoom;
	fractal->y_step = (double)P_y / 2.0 / fractal->zoom;
	x = -P_x;
	while(x < P_x)
	{
		y = -P_y;
		while(y < P_y)
		{
			fractal->x = (x + fractal->x_move) / fractal->x_step;
			fractal->y = (y + fractal->y_move) / fractal->y_step;
			fractal->C = init_complex(fractal->x, fractal->y);
			fractal->Z = init_complex(0, 0);
//			if (fast_check(fractal))
//				fractal->color = 0;
//			else
//			{
			iter = 0;
			while (iter < MAX_ITER && magnitude(fractal->Z) < 4.0)
			{
//					fractal->Z.im = fabs(fractal->Z.re * fractal->Z.im);
				fractal->Z = bur_square(fractal->Z);
//				fractal->Z.im = fabs(fractal->Z.re * fractal->Z.im);

				fractal->Z = add(fractal->Z, fractal->C);
				iter++;
			}
			fractal->color = colorize(iter, fractal);
//			}
			my_mlx_pixel_put(fractal, x + P_x, y + P_y, fractal->color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}