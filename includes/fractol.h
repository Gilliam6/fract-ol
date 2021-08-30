#ifndef FRACTOL_H
# define FRACTOL_H
# include "../mlx/mlx.h"
# include "../includes/fractol.h"
# ifndef MAX_X
#  define MAX_X 400
# endif
# ifndef MAX_Y
#  define MAX_Y 400
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
	img_data			img;
	double			Xstep;
	double			Ystep;
	double			R;
	double			zoom;
	int				iter;
	int				color;
} t_fract;
int close_win(int key, t_fract *fractal);

#endif
