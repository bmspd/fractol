#include "../includes/fractol.h"

static void	render(t_win *win)
{
	win->y = 0;
	while (win->y < win->height)
	{
		win->c.im = win->max.im - win->y * win->transition.im;
		win->x = 0;
		while (win->x < win->width)
		{
			win->c.re = win->min.re + win->x * win->transition.re;
			win->z = init_complex(win->c.re, win->c.im);
			win->i = 0;
			while ((win->z.re * win->z.re + win->z.im * win->z.im) <= 4
				&& win->i < win->max_i)
			{
				win->z = init_complex(win->z.re * win->z.re
						- win->z.im * win->z.im + win->c.re,
						2.0 * win->z.re * win->z.im + win->c.im);
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
	win->transition.re = (win->max.re - win->min.re) / (win->width - 1);
	win->transition.im = (win->max.im - win->min.im) / (win->height - 1);
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
	win->min.re = -2.0;
	win->min.im = -2.0;
	win->max.re = 2.0;
	win->max.im = 2.0;
	make_hint(win);
	put_menu(win);
	draw_mandelbrot_cycle(win);
	mlx_hook(win->win, 2, 1L << 0, key_press, win);
	mlx_hook(win->win, 4, 1L << 2, mouse_action, win);
	mlx_hook(win->win, 17, 1L << 17, x_destroy, 0);
	mlx_loop(win->mlx);
}
