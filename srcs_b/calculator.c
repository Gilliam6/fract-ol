/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 21:07:17 by rstephan          #+#    #+#             */
/*   Updated: 2021/09/15 21:07:19 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	fast_check(double x, double y)
{
	double	P;
	double	theta;
	double	Pc;

	P = sqrt((pow(x - 0.25, 2) + pow(y, 2)));
	theta = atan2(y, x - 0.25);
	Pc = 0.5 - 0.5 * cos(theta);
	if (P <= Pc)
		return (1);
	return (0);
}
