#include "../includes/fractol.h"

void my_mlx_pixel_put(t_fract *fract, int x, int y, int color)
{
	char	*dst;
	dst = fract->img.addr + (y * fract->img.line_length + x * (fract->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int colorize(int iter, t_fract *fractal)
{
	if (iter == MAX_ITER)
		return (0);
	return (create_trgb(0,
						0 + ((iter + fractal->color_split + 1) % 250),
						255 - (iter + fractal->color_split + 1) % 250,
						155 - (iter + fractal->color_split + 1) % 150));
}

