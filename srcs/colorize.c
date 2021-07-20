#include "../includes/fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int colorize(int iter)
{
	int color;
	if (iter == MAX_ITER)
		return (create_trgb(0, 0, 0, 0));
	color = create_trgb(0, 190 - iter * 4, 150 - 5 * iter,
						170 - iter * 5);
	return (color);
}
