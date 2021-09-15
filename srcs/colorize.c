/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:07:27 by rstephan          #+#    #+#             */
/*   Updated: 2021/09/15 21:07:29 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_fract *fract, int x, int y, int color)
{
	char	*dst;

	dst = fract->img.addr + (y * fract->img.line_length + x
			* (fract->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	colorize(double iter, int max_iter, int color_split, double bright)
{
	double	t;
	int		color;

	if (iter == max_iter)
		return (0);
	t = iter / max_iter;
	t += (1 - t) * bright;
	color = (t / ((color_split + 1) % 3 + 1) * 255);
	color <<= 8;
	color += (t / ((color_split + 2) % 3 + 1) * 255);
	color <<= 8;
	color += (t / ((color_split + 3) % 3 + 1) * 255);
	return (color);
}
