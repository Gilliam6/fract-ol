#include "../includes/fractol.h"

t_complex	square(t_complex complex)
{
	double temp;

	temp = (complex.re * complex.re) - (complex.im * complex.im);
	complex.im = 2.0 * complex.re * complex.im;
	complex.re = temp;
	return (complex);
}

double	magnitude(t_complex complex)
{
	return ((complex.re * complex.re) + (complex.im * complex.im));
}

t_complex add(t_complex z, t_complex c)
{
	z.re += c.re;
	z.im += c.im;
	return (z);
}