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

int fast_check(t_fract *fract)
{
	double P;
	double theta;
	double Pc;

	P = sqrt((pow(fract->C.re - 0.25, 2) + pow(fract->C.im, 2)));
	theta = atan2(fract->C.im, fract->C.re - 0.25);
	Pc = 0.5 - 0.5 * cos(theta);
	if (P <= Pc)
	{
		fract->iter = MAX_ITER;
		return (1);
	}
	return (0);
}

double radius(t_complex complex)
{
	return ((1 + sqrt(1 + 4 * magnitude(complex))) / 2);
}