#include "../includes/fractol.h"

void	utils_move(int button, t_fract *fractal)
{
	if (button == 123)
	{
		fractal->min.re -= 50 * fractal->x_step;
		fractal->max.re -= 50 * fractal->x_step;
	}
	if (button == 124)
	{
		fractal->min.re += 50 * fractal->x_step;
		fractal->max.re += 50 * fractal->x_step;
	}
	if (button == 126)
	{
		fractal->min.im -= 50 * fractal->y_step;
		fractal->max.im -= 50 * fractal->y_step;
	}
	if (button == 125)
	{
		fractal->min.im += 50 * fractal->y_step;
		fractal->max.im += 50 * fractal->y_step;
	}
}
