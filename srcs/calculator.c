#include "../includes/fractol.h"

double calculateR(double x, double y)
{
	return ((1 + sqrt(1 + 4 * fabs(x + y))) / 2);
}

double mods(double arg)
{
	return (sqrt(cos(arg * 2) + sin(arg * 2)));
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

int iterator(t_fract *fract)
{
	t_complex z1 = fract->Z;
	t_complex z2 = z1;
	int iter = 0;
	while(pow(z2.re, 2) + pow(z2.im, 2) < 4 && iter < MAX_ITER)
	{
		z2.re = pow(z1.re, 2) - pow(z1.im, 2) + fract->C.re;
		z2.im = 2 * z1.re * z1.im + fract->C.im;
		z1.re = z2.re;
		z1.im = z2.im;
		iter++;
	}
	return (iter);
}

//