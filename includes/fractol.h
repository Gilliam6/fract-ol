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
#  define MAX_ITER 100
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct complex_list
{
	double re;
	double im;
} t_complex;

typedef struct fract_list
{
	void 			*mlx;
	void 			*win;
	double			x;
	double			y;
	t_complex		C;
	t_complex 		Z;
	t_data			img;
	double			Xstep;
	double			Ystep;
	double			R;
	double			zoom;
	int				iter;
	int				color;
} t_fract;
double calculateR(double x, double y);
int iterator(t_fract *fract);
int colorize(int iter);
void render_man(t_fract *fractal);
int render_jul(t_fract *fractal);
int fast_check(t_fract *fract);

#endif
