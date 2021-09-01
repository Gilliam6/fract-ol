#include "../includes/fractol.h"

void mandelbrot(t_fract *fractal)
{
	int x;
	int y;
	int iter;
	double X_step;
	double Y_step;
	int P_x;
	int P_y;

	P_x = MAX_X / 2;
	P_y = MAX_Y / 2;
	X_step = (double)P_x / 2.0 / fractal->zoom;
	Y_step = (double)P_y / 2.0 / fractal->zoom;
	x = 0;
	while(x < MAX_X)
	{
		y = 0;
		while(y < MAX_Y)
		{
			fractal->x = ((double)((x + fractal->x_move) - P_x) / (double)
					(X_step));
			fractal->y = ((double)((y + fractal->y_move) - P_y) / (double)
					(Y_step));
			fractal->C = init_complex(fractal->x, fractal->y);
			fractal->Z = init_complex(0, 0);
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
				fractal->color = colorize(iter);
			}
			my_mlx_pixel_put(fractal, x, y, fractal->color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}

