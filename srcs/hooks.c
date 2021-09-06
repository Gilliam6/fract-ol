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
		fractal->zoom *= 1.2;
	}
	if (button == 5)
	{
		new_x = (x - MAX_X/ 2) * fractal->x_step;
		new_y = (y - MAX_Y/ 2) * fractal->y_step;
		fractal->zoom *= 0.8;
		fractal->x_move += new_x / (fractal->x_step * 0.8);
		fractal->y_move += new_y / (fractal->y_step * 0.8);
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
		fractal->x_move = 0;
		fractal->y_move = 0;
		fractal->zoom = 1;
	}
	if (button == 123)
		fractal->x_move -= 50 ;
	if (button == 124)
		fractal->x_move += 50 ;
	if (button == 126)
		fractal->y_move -= 50 ;
	if (button == 125)
		fractal->y_move += 50 ;
	data_flow(fractal);
	return (1);
}