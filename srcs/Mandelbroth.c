#include "../includes/fractol.h"

void	mandelbrot(t_fract *fractal)
{
	int	iter;

	fractal->C = init_complex(fractal->x, fractal->y);
	fractal->Z = init_complex(0, 0);
	if (fast_check(fractal))
		fractal->color = 0;
	else
	{
		iter = 0;
		while (iter < fractal->MAX_ITER && magnitude(fractal->Z) < 4.0)
		{
			fractal->Z = square(fractal->Z);
			fractal->Z = add(fractal->Z, fractal->C);
			iter++;
		}
		fractal->color = colorize(iter, fractal);
	}
}
