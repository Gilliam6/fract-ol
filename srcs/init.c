/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:08:12 by rstephan          #+#    #+#             */
/*   Updated: 2021/09/15 21:08:13 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

t_fract	init_fractal(char *set)
{
	t_fract	fractal;

	fractal.set = name_check(set);
	fractal.MAX_ITER = 30;
	fractal.min.re = -2;
	fractal.min.im = -2;
	fractal.max.re = 2;
	fractal.max.im = 2;
	if (MAX_X > MAX_Y)
		fractal.max.re *= MAX_X / MAX_Y;
	if (MAX_X < MAX_Y)
		fractal.max.im *= MAX_Y / MAX_X;
	fractal.x_step = fabs(fractal.max.re - fractal.min.re) / MAX_X;
	fractal.y_step = fabs(fractal.max.im - fractal.min.im) / MAX_Y;
	fractal.color_split = 1;
	fractal.click = init_complex(0.12, -0.3);
	fractal.jul_flag = 0;
	fractal.bright = 0;
	return (fractal);
}
