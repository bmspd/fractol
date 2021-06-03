#include "../includes/fractol.h"

static void	render(t_win *win)
{
	win->y = 0;
	while (win->y < win->height)
	{
		win->c.i = win->max.i - win->y * win->transition.i;
		win->x = 0;
		while (win->x < win->width)
		{
			win->c.r = win->min.r + win->x * win->transition.r;
			win->z = make_complex(win->c.r, win->c.i);
			win->i = 0;
			while ((win->z.r * win->z.r + win->z.i * win->z.i) <= 4
				&& win->i < win->max_i)
			{
				win->z = make_complex(win->z.r * win->z.r
						- win->z.i * win->z.i + win->c.r,
						2.0 * win->z.r * win->z.i + win->c.i);
				win->i++;
			}
			color_pixel(win, (double)win->i / win->max_i);
			win->x++;
		}
		win->y++;
	}
}

int	draw_mandelbrot_cycle(t_win *win)
{
	win->main.img = mlx_new_image(win->mlx, win->width, win->height);
	win->main.addr = mlx_get_data_addr(win->main.img, &win->main.bits_per_pixel,
			&win->main.line_length, &win->main.endian);
	win->transition.r = (win->max.r - win->min.r) / (win->width - 1);
	win->transition.i = (win->max.i - win->min.i) / (win->height - 1);
	render(win);
	mlx_put_image_to_window(win->mlx, win->win, win->main.img, 0, 0);
	mlx_put_image_to_window(win->mlx, win->win, win->hint.img,
		(int)(0.76 * win->width), (int)(0.9 * win->height));
	return (0);
}

void	mandelbrot_init(t_win *win)
{
	win->type_flag = 1;
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, win->width, win->height, "Mandelbrot");
	win->min.r = -2.0;
	win->min.i = -2.0;
	win->max.r = 2.0;
	win->max.i = 2.0;
	make_hint(win);
	put_menu(win);
	draw_mandelbrot_cycle(win);
	mlx_hook(win->win, 2, 1L << 0, key_press, win);
	mlx_hook(win->win, 4, 1L << 2, mouse_action, win);
	mlx_hook(win->win, 17, 1L << 17, x_destroy, 0);
	mlx_loop(win->mlx);
}
