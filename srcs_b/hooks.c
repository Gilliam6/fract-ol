/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:08:01 by rstephan          #+#    #+#             */
/*   Updated: 2021/09/15 21:08:03 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	close_win(t_fract *fractal)
{
	mlx_destroy_window(fractal->mlx, fractal->win);
	exit(0);
}

int	julia_complex(int x, int y, t_fract *fractal)
{
	if (fractal->jul_flag)
	{
		fractal->click.re = -2 + x * (4.0 / MAX_X);
		fractal->click.im = -2 + y * (4.0 / MAX_Y);
	}
	draw_bonus(fractal);
	return (1);
}

void	change_bright(int button, t_fract *fractal)
{
	if (button == 9)
		if (fractal->bright < 1)
			fractal->bright += 0.01;
	if (button == 8)
		if (fractal->bright > 0)
			fractal->bright -= 0.01;
}

void	zoom_in_out(t_fract *fractal, int x, int y, double zoom)
{
	double	new_x;
	double	new_y;

	new_x = fractal->min.re + x * fractal->x_step;
	new_y = fractal->min.im + y * fractal->y_step;
	fractal->x_step *= zoom;
	fractal->y_step *= zoom;
	fractal->min.re = new_x + ((fractal->min.re - new_x) * zoom);
	fractal->min.im = new_y + ((fractal->min.im - new_y) * zoom);
	fractal->max.re = new_x + ((fractal->max.re - new_x) * zoom);
	fractal->max.im = new_y + ((fractal->max.im - new_y) * zoom);
}

int	arrows(int button, t_fract *fractal)
{
	if (button == 9 || button == 8)
		change_bright(button, fractal);
	if (button == 53)
		close_win(fractal);
	if (button == 18)
		fractal->color_split = (fractal->color_split + 1) % 3;
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
	draw_bonus(fractal);
	return (1);
}
