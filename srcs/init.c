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
	fractal.min.re = -2;
	fractal.min.im = -2;
	fractal.max.re = 2;
	fractal.max.im = 2;
	fractal.x_move = 0;
	fractal.y_move = 0;
	fractal.x_step = 0;
	fractal.y_step = 0;
	fractal.color_split = 1;
	return (fractal);
}