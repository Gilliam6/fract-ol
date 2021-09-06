#include "../includes/fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex complex;

	complex.re = re;
	complex.im = im;
	return(complex);
}

t_fract	init_fractal(char *set)
{
	t_fract fractal;

	fractal.set = set;
	fractal.zoom = 1;
	fractal.x_move = 0;
	fractal.y_move = 0;
	fractal.x_step = (double)(MAX_X / 4 / fractal.zoom);
	fractal.y_step = (double)(MAX_Y / 4 / fractal.zoom);
	fractal.color_split = 1;
	return (fractal);
}