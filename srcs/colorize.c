#include "../includes/fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int colorize(int iter)
{
	if (iter == MAX_ITER)
		return (0);
	return (create_trgb(0, 255 - iter * 4, 155 + iter * 2, 255 - iter * 4));
}
