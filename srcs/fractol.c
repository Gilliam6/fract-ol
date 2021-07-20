#include "../includes/fractol.h"

int close_win(int key, t_fract *fractal)
{
	if (key == 53)
	{
		mlx_destroy_window(fractal->mlx, fractal->win);
		exit(0);
	}
	return (1);
}

int	zoom(int button, int x, int y,t_fract *fractal)
{
	(void) x;
	(void) y;
//	printf("button|%d\n", button);
//	printf("x|%d\n", x);
//	printf("y|%d\n", y);

	if (button == 4)
	{
		fractal->zoom += 10;
		fractal->C.im += 0.01;
		fractal->C.re -= 0.01;
		render_jul(fractal);
	}
	if (button == 5)
	{
		fractal->zoom -= 10;
		fractal->C.im += 0.01;
		fractal->C.re -= 0.01;
		render_jul(fractal);
	}
//	mlx_loop_hook(fractal->mlx, render_jul, fractal);
	return (1);
}

void my_mlx_pixel_put(t_fract *fract, int x, int y, int color)
{
	char	*dst;
	dst = fract->img.addr + (y * fract->img.line_length + x * (fract->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void render_man(t_fract *fractal)
{
	fractal->x = 0;
	fractal->y = 0;
//	printf("%f | %f\n", fractal->C.re, fractal->C.im);
//	fractal->C.re = -2;
//	fractal->C.im = -2;
	fractal->R = calculateR(fractal->C.re, fractal->C.im);
	fractal->Xstep = fabs(fractal->R - (-fractal->R)) / MAX_X ;
	fractal->Ystep = fabs(fractal->R - (-fractal->R)) / MAX_Y;
	while(fractal->x < MAX_X - 1|| fractal->y < MAX_Y - 1)
	{
		if (fractal->x == MAX_X - 1)
		{
			fractal->x = 0;
			fractal->y++;
		}
		fractal->iter = iterator(fractal);
		fractal->color = colorize(fractal->iter);
		my_mlx_pixel_put(fractal, fractal->x, fractal->y, fractal
				->color);
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
}

int render_jul(t_fract *fractal)
{
	double x = MAX_X / 2;
	double y = MAX_Y / 2;
//	double scale = x / 2;
	fractal->x = -x;
	fractal->y = -y;
//	fractal->R = 250;
//	fractal->C.re = fractal->x / scale;
//	fractal->C.im = -fractal->y / scale;
//	fractal->C.re = -0.85;
//	fractal->C.im = 0.156;
	while(fractal->x < x - 1|| fractal->y < y - 1)
	{
		if (fractal->x == x - 1)
		{
			fractal->x = -x;
			fractal->y++;
		}
		fractal->Z.re = fractal->x / fractal->zoom;
		fractal->Z.im = fractal->y / fractal->zoom;
		fractal->iter = iterator(fractal);
		fractal->color = colorize(fractal->iter);
		my_mlx_pixel_put(fractal, fractal->x + x, fractal->y + y,
						 fractal
				->color);
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img.img, 0, 0);
	return (1);
}

int main()
{
	t_fract fractal;

	fractal.C.re = -0.8;
	fractal.C.im = 0.134;

	fractal.mlx = mlx_init();
	fractal.win = mlx_new_window(fractal.mlx, MAX_X, MAX_Y, "fractol\'");

	fractal.img.img = mlx_new_image(fractal.mlx, MAX_X, MAX_Y);
	fractal.img.addr = mlx_get_data_addr(fractal.img.img, &fractal
	.img.bits_per_pixel, &fractal.img.line_length, &fractal.img.endian);
	fractal.zoom = MAX_X / 4;
	render_jul(&fractal);
//	mlx_put_image_to_window(fractal.mlx, fractal.win, fractal.img.img, 0, 0);

	mlx_hook(fractal.win, 2, 1l<<0, close_win, &fractal);
	mlx_mouse_hook(fractal.win, zoom, &fractal);

	mlx_loop(fractal.mlx);
}