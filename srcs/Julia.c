#include "../includes/fractol.h"

void julia(t_fract *fractal)
{
	int x;
	int y;
	int iter;
	double X_step;
	double Y_step;

	fractal->C = init_complex(-0.2, 0.75);
	fractal->R = radius(fractal->C);
	X_step = (double)MAX_X / 2.0 / fractal->zoom;
	Y_step = (double)MAX_Y / 2.0 / fractal->zoom;
	x = -MAX_X / 2;
	while(x < MAX_X / 2)
	{
		y = -MAX_Y / 2;
		while(y < MAX_Y / 2)
		{
			fractal->x = x / X_step;
			fractal->y = y / Y_step;
//			fractal->C = init_complex(fractal->x, fractal->y);
			fractal->Z = init_complex(fractal->x, fractal->y);
			iter = 0;
			while (iter < MAX_ITER && magnitude(fractal->Z) < 4.0)
			{
				fractal->Z = square(fractal->Z);
				fractal->Z = add(fractal->Z, fractal->C);
				iter++;
			}
//			ft_putnbr_fd(magnitude(fractal->Z) < 4.0,1);
			fractal->color = colorize(iter);
			my_mlx_pixel_put(fractal, x + MAX_X / 2, y + MAX_Y / 2,
							 fractal->color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);

}
