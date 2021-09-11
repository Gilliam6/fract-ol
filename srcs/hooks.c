#include "../includes/fractol.h"

int close_win(int key, t_fract *fractal)
{
	if (key == 53)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(0);
	}
	return (1);
}

int	zoom(int button, int x, int y,t_fract *fractal)
{
	double new_x;
	double new_y;

	if (button == 4)
	{
		fractal->max.re *= 1.2;
		fractal->max.im *= 1.2;
		fractal->min.re *= 1.2;
		fractal->min.im *= 1.2;;
	}
	if (button == 5)
	{
		// находим центр новой области координат
		new_x = fractal->min.re + x * fractal->x_step;
		new_y = fractal->min.re + y * fractal->y_step;
		// меняем наш степ на каждый пиксель
		fractal->x_step *= 0.8;
		fractal->y_step *= 0.8;
		// высчитываем новые координаты
		fractal->min.re = new_x - (MAX_X / 2) * fractal->x_step;
		fractal->min.im = new_y - (MAX_Y / 2) * fractal->y_step;
		fractal->max.re = fractal->min.re + MAX_X * fractal->x_step;
		fractal->max.im = fractal->min.im + MAX_Y * fractal->y_step;
//		fractal->x_move += new_x / (fractal->x_step * 0.8);
//		fractal->y_move += new_y / (fractal->y_step * 0.8);
	}
	data_flow(fractal);
	return (1);
}

int arrows(int button, t_fract *fractal)
{
	// 123 left
	// 126 up
	// 124 right
	// 125 down

	if (button == 18)
		fractal->color_split += 10;
	if (button == 19)
		fractal->color_split = 1;
	if (button == 15)
	{
		fractal->min = init_complex(-2, -2);
		fractal->max = init_complex(2, 2);
		fractal->x_step = 0;
		fractal->y_step = 0;
	}
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
	data_flow(fractal);
	return (1);
}