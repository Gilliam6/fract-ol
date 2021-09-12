#include "../includes/fractol.h"

void	julia(t_fract *fractal)
{
	int	iter;

	fractal->C = init_complex(-0.5, 0.3);
	fractal->Z = init_complex(fractal->x, fractal->y);
	iter = 0;
	while (iter < MAX_ITER && magnitude(fractal->Z) < 4.0)
	{
		fractal->Z = square(fractal->Z);
		fractal->Z = add(fractal->Z, fractal->C);
		iter++;
	}
	fractal->color = colorize(iter, fractal);
}
