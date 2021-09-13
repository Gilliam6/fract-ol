#include "../includes/fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_fract	init_fractal(char *set)
{
	t_fract	fractal;

	fractal.set = set;
	fractal.MAX_ITER = 30;
	fractal.min.re = -2;
	fractal.min.im = -2;
	fractal.max.re = 2;
	fractal.max.im = 2;
	fractal.x_step = fabs(fractal.max.re - fractal.min.re) / MAX_X;
	fractal.y_step = fabs(fractal.max.im - fractal.min.im) / MAX_Y;
	fractal.color_split = 1;
	fractal.click = init_complex(0.12, -0.3);
	fractal.jul_flag = 0;
	return (fractal);
}
