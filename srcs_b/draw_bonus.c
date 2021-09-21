#include "../includes/fractol_bonus.h"
#include <pthread.h>

void	data_flow(t_fract *fractal)
{
	if (fractal->set == 0)
		mandelbrot(fractal);
	else if (fractal->set == 1)
		julia(fractal);
	else
		burning_ship(fractal);
}

void	draw_part(t_fract *fractols)
{
	int x;
	int y;

	fractols->y = fractols->min.im + fractols->y_step *
			fractols->border_up;
	y = fractols->border_up;
	while (y < fractols->border_bottom)
	{
		x = 0;
		fractols->x = fractols->min.re;
		while (x < MAX_X)
		{
//			ft_putnbr_fd(x, 1);
//			write(1, "x\n", 2);
			data_flow(fractols);
			my_mlx_pixel_put(fractols, x, y, fractols->color);
			fractols->x += fractols->x_step;
			x++;
		}
//		ft_putnbr_fd(y, 1);
//		write(1, "y\n", 2);
		fractols->y += fractols->y_step;
		y++;
	}
}

void	draw_bonus(t_fract *fractal)
{
	int	i;
	pthread_t my_thread[8];
	t_fract fractols[8];

	i = 0;
	while (i < 8)
	{
		fractols[i] = *fractal;
		fractols[i].border_up = i * (MAX_Y / 8);
		fractols[i].border_bottom = (i + 1) * (MAX_Y / 8);
		if (pthread_create(&my_thread[i], NULL, (void *(*) (void *))draw_part,
				&fractols[i]))
			my_exit(-1);
//		ft_putnbr_fd(i, 1);
//		write(1, "i\n", 2);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(my_thread[i], NULL))
			my_exit(-1);
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}


