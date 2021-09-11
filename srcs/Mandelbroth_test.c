#include "../includes/fractol.h"

void mandelbrot(t_fract *fractal)
{
	int x;
	int y;
	int iter;

	if (!fractal->x_step & !fractal->y_step)
	{
		fractal->x_step = fabs(fractal->max.re - fractal->min.re) / MAX_X;
		fractal->y_step = fabs(fractal->max.im - fractal->min.im) / MAX_Y;
	}
	x = 0;
	fractal->x = fractal->min.re;
	fractal->y = fractal->min.im;
	while(x < MAX_X)
	{
		y = 0;
		fractal->y = fractal->min.im;
		while(y < MAX_Y)
		{
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
				fractal->color = colorize(iter, fractal);
			}
			my_mlx_pixel_put(fractal, x, y, fractal->color);
			fractal->y += fractal->y_step;
			y++;
		}
		fractal->x += fractal->x_step;
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}

