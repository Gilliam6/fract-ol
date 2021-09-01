#ifndef FRACTOL_H
# define FRACTOL_H
# include "../mlx/mlx.h"
# include "../includes/fractol.h"
# ifndef MAX_X
#  define MAX_X 800
# endif
# ifndef MAX_Y
#  define MAX_Y 800
# endif
# ifndef MAX_ITER
#  define MAX_ITER 50
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct complex_list
{
	double re;
	double im;
} 				t_complex;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				img_data;

typedef struct fract_list
{
	void 			*mlx;
	void 			*win;
	double			x;
	double			y;
	t_complex		C;
	t_complex 		Z;
	img_data		img;
	double			R;
	double			zoom;
	int				iter;
	int				color;
	char			*set;
	int				x_move;
	int 			y_move;
} t_fract;
void	data_flow(t_fract *fractal);
int close_win(int key, t_fract *fractal);
//void julia(t_fract fractal);
void mandelbrot(t_fract *fractal);
void julia(t_fract *fractal);
t_complex	init_complex(double re, double im);
double	magnitude(t_complex complex);
t_complex	add(t_complex z, t_complex c);
t_complex	square(t_complex complex);
void my_mlx_pixel_put(t_fract *fract, int x, int y, int color);
int	create_trgb(int t, int r, int g, int b);
int colorize(int iter);
t_complex	init_complex(double re, double im);
int fast_check(t_fract *fract);
double radius(t_complex complex);
int	zoom(int button, int x, int y,t_fract *fractal);
int arrows(int button, t_fract *fractal);

#endif
