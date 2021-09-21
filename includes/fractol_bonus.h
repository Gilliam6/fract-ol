/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:37:35 by rstephan          #+#    #+#             */
/*   Updated: 2021/09/15 20:37:38 by rstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../mlx/mlx.h"
# include "../includes/fractol.h"
# ifndef MAX_X
#  define MAX_X 400.0
# endif
# ifndef MAX_Y
#  define MAX_Y 400.0
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct complex_list
{
	double	re;
	double	im;
}				t_complex;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img_data;

typedef struct fract_list
{
	void			*mlx;
	void			*win;
	double			x;
	double			y;
	int				MAX_ITER;
	t_complex		C;
	t_complex		Z;
	t_complex		max;
	t_complex		min;
	t_complex		click;
	t_img_data		img;
	int 			border_up;
	int 			border_bottom;
	int				color;
	char			set;
	double			x_step;
	double			y_step;
	int				color_split;
	int				jul_flag;
	double			bright;
}				t_fract;

int			name_check(char *f_name);
void		data_flow(t_fract *fractal);
void		mandelbrot(t_fract *fractal);
void		julia(t_fract *fractal);
t_complex	init_complex(double re, double im);
void		my_mlx_pixel_put(t_fract *fract, int x, int y, int color);
int			colorize(double iter, int max_iter, int color_split, double bright);
t_complex	init_complex(double re, double im);
int			fast_check(double x, double y);
int			zoom(int button, int x, int y, t_fract *fractal);
int			arrows(int button, t_fract *fractal);
void		burning_ship(t_fract *fractal);
t_complex	bur_square(t_complex complex);
t_fract		init_fractal(char *set);
void		draw_bonus(t_fract *fractal);
int			julia_complex(int x, int y, t_fract *fractal);
void		utils_move(int button, t_fract *fractal);
int			zoom(int button, int x, int y, t_fract *fractal);
void		zoom_in_out(t_fract *fractal, int x, int y, double zoom);
int			my_exit(int err_num);

#endif
