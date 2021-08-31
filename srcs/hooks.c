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
	printf("button|%d\n", button);
	printf("x|%d\n", x);
	printf("y|%d\n", y);

	if (button == 4)
		fractal->zoom *= 2;
	if (button == 5)
		fractal->zoom /= 2;
	data_flow(fractal);

//	mlx_loop_hook(fractal->mlx, render_jul, fractal);
	return (1);
}