/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:07:49 by rstephan          #+#    #+#             */
/*   Updated: 2021/09/15 21:07:50 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	my_exit(int err_num)
{
	if (err_num == -1)
		ft_putstr_fd("Invalid arguments\n", 1);
	if (err_num == -2)
		ft_putstr_fd("Mlx init fail\n", 1);
	if (err_num == -3)
		ft_putstr_fd("New window init fail\n", 1);
	exit (0);
}

int	name_check(char *f_name)
{
	if (!ft_strncmp(f_name, "Mandelbrot", 10))
		return (0);
	if (!ft_strncmp(f_name, "Julia", 5))
		return (1);
	if (!ft_strncmp(f_name, "Burning ship", 12))
		return (2);
	return (-1);
}

void	fractal(char *set)
{
	t_fract	fractal;

	fractal = init_fractal(set);
	fractal.mlx = mlx_init();
	if (!fractal.mlx)
		my_exit(-2);
	fractal.win = mlx_new_window(fractal.mlx, MAX_X, MAX_Y, set);
	if (!fractal.win)
		my_exit(-3);
	fractal.img.img = mlx_new_image(fractal.mlx, MAX_X, MAX_Y);
	fractal.img.addr = mlx_get_data_addr(fractal.img.img, &fractal
			.img.bits_per_pixel, &fractal.img.line_length, &fractal.img.endian);
	draw_bonus(&fractal);
	mlx_hook(fractal.win, 6, 1l << 6, julia_complex, &fractal);
	mlx_mouse_hook(fractal.win, zoom, &fractal);
	mlx_hook(fractal.win, 2, 1L << 0, arrows, &fractal);
	mlx_loop(fractal.mlx);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || (name_check(argv[1]) == -1))
		return (my_exit(-1));
	fractal(argv[1]);
	return (0);
}
