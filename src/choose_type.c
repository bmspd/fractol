#include "../includes/fractol.h"

void	choose_type_draw(t_win *win)
{
	if (win->type_flag == 0)
		draw_julia_cycle(win);
	else if (win->type_flag == 1)
		draw_mandelbrot_cycle(win);
	else if (win->type_flag == 2)
		draw_mandelbar_cycle(win);
}
