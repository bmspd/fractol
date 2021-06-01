#include "../includes/fractol.h"

void	color_pixel(t_win *win, double t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 -t) * t * t * 255);
	b = (int)(8.5 * (1 -t) * (1 - t) * (1 - t) * t * 255);
	if (win->flag_c == 0)
		image_pixel_put(&win->main, win->x, win->y, (r << 16 | g << 8 | b));
	else if (win->flag_c == 1)
		image_pixel_put(&win->main, win->x, win->y, (r << 16 | b << 8 | g));
	else if (win->flag_c == 2)
		image_pixel_put(&win->main, win->x, win->y, (g << 16 | r << 8 | b));
	else if (win->flag_c == 3)
		image_pixel_put(&win->main, win->x, win->y, (g << 16 | b << 8 | r));
	else if (win->flag_c == 4)
		image_pixel_put(&win->main, win->x, win->y, (b << 16 | r << 8 | g));
	else if (win->flag_c == 5)
		image_pixel_put(&win->main, win->x, win->y, (b << 16 | g << 8 | r));
}
