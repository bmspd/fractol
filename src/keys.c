#include "../includes/fractol.h"
double	transfer(double left, double right, double coefficient)
{
	double	transfer;

	transfer = left + (right - left) * coefficient;
	return (transfer);
}

static void	key_m_behaviour(t_win *win)
{
	if (win->flag_m == 0)
	{
		make_menu(win);
		win->flag_m = 1;
	}
	else
	{
		mlx_put_image_to_window(win->mlx, win->win, win->main.img, 0, 0);
		mlx_put_image_to_window(win->mlx, win->win, win->hint.img,
			  (int)(0.76 * win->width), (int)(0.9 * win->height));
		win->flag_m = 0;
	}
}

int	key_press(int keycode, t_win *win)
{
	if (keycode == 46)
		key_m_behaviour(win);
	if (keycode == 8)
	{
		win->flag_c++;
		if (win->flag_c == 6)
			win->flag_c = 0;
		choose_type_draw(win);
	}
	if (keycode == 53)
	{
		printf("Exiting from fract-ol...\n");
		exit(0);
	}
	return (0);
}

int	x_destroy(void)
{
	printf("Exiting from fract-ol...\n");
	exit(0);
}

int	mouse_action(int mouse_code, int x, int y, t_win *win)
{
	double	zoom;
	double	coefficient;

	if (mouse_code == 5 || mouse_code == 4)
	{
		mlx_destroy_image(win->mlx, win->main.img);
		win->cursor = make_complex((double)x / (win->width
					/ (win->max.r - win->min.r)) + win->min.r,
				(double)y / (win->height
					/ (win->max.i - win->min.i)) + win->min.i);
		if (mouse_code == 5)
			zoom = 1.2;
		else
			zoom = 0.5;
		coefficient = 1 / zoom;
		win->min.r = transfer(win->cursor.r, win->min.r, coefficient);
		win->min.i = transfer(win->cursor.i, win->min.i, coefficient);
		win->max.r = transfer(win->cursor.r, win->max.r, coefficient);
		win->max.i = transfer(win->cursor.i, win->max.i, coefficient);
		choose_type_draw(win);
		mlx_do_sync(win->mlx);
	}
	return (0);
}
