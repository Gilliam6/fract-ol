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
	(void) x;
	(void) y;

	if (button == 4)
		fractal->zoom *= 1.2;
	if (button == 5)
		fractal->zoom *= 0.8;
	data_flow(fractal);
	return (1);
}

int arrows(int button, t_fract *fractal)
{
	// 123 left
	// 126 up
	// 124 right
	// 125 down
//	ft_putnbr_fd(button, 1);
	if (button == 15)
	{
		fractal->x_move = 0;
		fractal->y_move = 0;
	}
	if (button == 123)
		fractal->x_move -= 50;
	if (button == 124)
		fractal->x_move += 50;
	if (button == 126)
		fractal->y_move -= 50;
	if (button == 125)
		fractal->y_move += 50;
	data_flow(fractal);
	return (1);
}