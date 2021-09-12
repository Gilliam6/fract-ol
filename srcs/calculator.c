#include "../includes/fractol.h"

t_complex	square(t_complex complex)
{
	double	temp;

	temp = (complex.re * complex.re) - (complex.im * complex.im);
	complex.im = 2.0 * complex.re * complex.im;
	complex.re = temp;
	return (complex);
}

double	magnitude(t_complex complex)
{
	return ((complex.re * complex.re) + (complex.im * complex.im));
}

t_complex	add(t_complex z, t_complex c)
{
	z.re += c.re;
	z.im += c.im;
	return (z);
}

int	fast_check(t_fract *fract)
{
	double	P;
	double	theta;
	double	Pc;

	P = sqrt((pow(fract->x - 0.25, 2) + pow(fract->y, 2)));
	theta = atan2(fract->y, fract->x - 0.25);
	Pc = 0.5 - 0.5 * cos(theta);
	if (P <= Pc)
		return (1);
	return (0);
}
