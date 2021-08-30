#include "../includes/fractol.h"

int	my_exit(int err_num)
{
	if (err_num == -1)
		ft_putstr_fd("Invalid arguments\n", 1);

	return (err_num);
}

int	name_check(char *f_name)
{
	char	fractals[2][15] = {"Mandelbrot", "Julia"};
	int		set;
	int		index;

	set = 0;
	while(set < 2)
	{
		index = 0;
		while (f_name[index] && fractals[set][index] == f_name[index])
			index++;
		if (!f_name[index] && !fractals[set][index])
			return (set);
		set++;
	}
	return (-1);
}

void	data_flow(t_fract *fractal, char *set)
{
	fractal->zoom = 1;

	if (name_check(set) == 0)
	{
		mandelbrot(fractal);
	}
//	if (set == jul)
//		julia(fractal);
}
void	fractal(char *set)
{
	t_fract fractal;

	// mlx and window init
	fractal.mlx = mlx_init();
	fractal.win = mlx_new_window(fractal.mlx, MAX_X, MAX_Y, "fractol\'");

	// mlx image init
	fractal.img.img = mlx_new_image(fractal.mlx, MAX_X, MAX_Y);
	fractal.img.addr = mlx_get_data_addr(fractal.img.img, &fractal
			.img.bits_per_pixel, &fractal.img.line_length, &fractal.img.endian);

	// Fractal branches
	data_flow(&fractal, set);
	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.img.img, 0, 0);

	// base hooks
	mlx_hook(fractal.win, 2, 1l<<0, close_win, &fractal);
	mlx_loop(fractal.mlx);
}

int main(int argc, char **argv)
{
	if (argc != 2 || (name_check(argv[1]) == -1))
		return (my_exit(-1));

	fractal(argv[1]);
	return (0);
}