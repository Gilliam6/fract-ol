/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:08:46 by rstephan          #+#    #+#             */
/*   Updated: 2021/09/15 21:08:54 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	zoom(int button, int x, int y, t_fract *fractal)
{
	if (button == 4)
		zoom_in_out(fractal, x, y, 1.2);
	if (button == 5)
		zoom_in_out(fractal, x, y, 0.8);
	draw(fractal);
	return (1);
}
