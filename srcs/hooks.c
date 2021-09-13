#include "../includes/fractol.h"

int	close_win(int key, t_fract *fractal)
{
	if (key == 53)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(0);
	}
	return (1);
}

int	julia_complex(int x, int y, t_fract *fractal)
{
	if (fractal->jul_flag)
	{
		fractal->click.re = -2 + x * (4.0 / MAX_X);
		fractal->click.im = -2 + y * (4.0 / MAX_Y);
	}
	draw(fractal);
	return (1);
}

int	zoom(int button, int x, int y, t_fract *fractal)
{
	double	new_x;
	double	new_y;

	if (button == 4)
	{
		fractal->max.re *= 1.2;
		fractal->max.im *= 1.2;
		fractal->min.re *= 1.2;
		fractal->min.im *= 1.2;
		fractal->x_step *= 1.2;
		fractal->y_step *= 1.2;
	}
	if (button == 5)
	{
		new_x = fractal->min.re + x * fractal->x_step;
		new_y = fractal->min.im + y * fractal->y_step;
		fractal->x_step *= 0.8;
		fractal->y_step *= 0.8;
		fractal->min.re = new_x - (MAX_X / 2) * fractal->x_step;
		fractal->min.im = new_y - (MAX_Y / 2) * fractal->y_step;
		fractal->max.re = fractal->min.re + MAX_X * fractal->x_step;
		fractal->max.im = fractal->min.im - MAX_Y * fractal->y_step;
	}
	draw(fractal);
	return (1);
}

int	arrows(int button, t_fract *fractal)
{
	if (button == 18)
		fractal->color_split += 10;
	if (button == 19)
		fractal->jul_flag = !fractal->jul_flag;
	if (button >= 123 && button <= 126)
		utils_move(button, fractal);
	if (button == 24)
		fractal->MAX_ITER += 5;
	if (button == 27)
		fractal->MAX_ITER -= 5;
	if (button == 15)
	{
		fractal->min.re = -2;
		fractal->min.im = -2;
		fractal->max.re = 2;
		fractal->max.im = 2;
		fractal->x_step = fabs(fractal->max.re - fractal->min.re) / MAX_X;
		fractal->y_step = fabs(fractal->max.im - fractal->min.im) / MAX_Y;
	}
	draw(fractal);
	return (1);
}
