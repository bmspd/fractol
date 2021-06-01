#include "../includes/fractol.h"

void	make_hint(t_win *win)
{
	int	width;
	int	height;

	win->hint.img = mlx_xpm_file_to_image(win->mlx,
			"./table.xpm", &width, &height);
}

void 	make_menu(t_win *win)
{
	int	width;
	int	height;

	mlx_put_image_to_window(win->mlx, win->win, win->squares.img, 0, 0);
	win->menu.img = mlx_xpm_file_to_image(win->mlx,
			"./lsd.xpm", &width, &height);
	mlx_put_image_to_window(win->mlx, win->win, win->menu.img,
		 (int)(0.19 * win->width), (int)(0.2 * win->height));
}

void	put_menu(t_win *win)
{
	int	y;
	int	x;

	win->squares.img = mlx_new_image(win->mlx, win->width, win->height);
	win->squares.addr = mlx_get_data_addr(win->squares.img,
			&win->squares.bits_per_pixel, &win->squares.line_length,
			&win->squares.endian);
	y = 0;
	while (y < win->height)
	{
		x = 0;
		while (x < win->width)
			image_pixel_put(&win->squares, x++, y, (int)0x88FFFFFF);
		y++;
	}
	y = (int)(0.1 * win->height);
	while (y < win->height * 0.9)
	{
		x = (int)(0.1 * win->width);
		while (x < win->width * 0.9)
			image_pixel_put(&win->squares, x++, y, (int)0x88000000);
		y++;
	}
}
