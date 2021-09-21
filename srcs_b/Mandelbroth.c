/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbroth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:08:34 by rstephan          #+#    #+#             */
/*   Updated: 2021/09/15 21:08:36 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

void	mandelbrot(t_fract *fractal)
{
	int		iter;
	double	zr2;
	double	zi2;

	fractal->C = init_complex(fractal->x, fractal->y);
	fractal->Z = init_complex(0, 0);
	zr2 = fractal->Z.re * fractal->Z.re;
	zi2 = fractal->Z.im * fractal->Z.im;
	iter = -1;
	if (fast_check(fractal->x, fractal->y))
		fractal->color = 0;
	else
	{
		while (++iter < fractal->MAX_ITER && zr2 + zi2 < 4.0)
		{
			fractal->Z.im = fractal->Z.re * fractal->Z.im;
			fractal->Z.im += fractal->Z.im;
			fractal->Z.im += fractal->C.im;
			fractal->Z.re = zr2 - zi2 + fractal->C.re;
			zr2 = fractal->Z.re * fractal->Z.re;
			zi2 = fractal->Z.im * fractal->Z.im;
		}
		fractal->color = colorize(
				iter, fractal->MAX_ITER, fractal->color_split, fractal->bright);
	}
}
