#include "../includes/fractol.h"

double calculateR(double x, double y)
{
	return ((1 + sqrt(1 + 4 * fabs(x + y))) / 2);
}

int iterator(t_fract *fract)
{
	int iter;
	t_complex Z;
	t_complex C;

	iter = 0;
	C.re = fract->C.re;
	C.im = fract->C.im;
	Z.re = fract->Z.re;
	Z.im = fract->Z.im;

	while (pow(Z.re, 2.0) + pow(Z.im, 2.0) < 2
		   && iter < MAX_ITER)
	{
		Z.re = pow(Z.re, 2.0) - pow(Z.im, 2.0) + C.re;
		Z.im = 2.0 * Z.re * Z.im + C.im;
		iter++;
	}
	return (iter);
}

