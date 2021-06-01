#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
typedef struct s_complex {
	double	re;
	double	im;
}t_complex;
typedef struct s_img {
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}	t_img;
typedef struct s_win {
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	int			flag_m;
	int			flag_c;
	int			x;
	int			y;
	int			max_i;
	int			i;
	int			type_flag;
	t_img		main;
	t_img		menu;
	t_img		squares;
	t_img		hint;
	t_complex	min;
	t_complex	max;
	t_complex	transition;
	t_complex	k;
	t_complex	c;
	t_complex	z;
	t_complex	cursor;
}	t_win;

t_complex	init_complex(double re, double im);
void		mandelbrot_init(t_win *win);
void		image_pixel_put(t_img *img, int x, int y, int color);
int			key_press(int keycode, t_win *win);
int			mouse_action(int mouse_code, int x, int y, t_win *win);
int			draw_mandelbrot_cycle(t_win *win);
int			draw_julia_cycle(t_win *win);
int			draw_mandelbar_cycle(t_win *win);
void		put_menu(t_win *win);
void		make_hint(t_win *win);
void		make_menu(t_win *win);
void		color_pixel(t_win *win, double t);
void		julia_init(t_win *win);
void		mandelbar_init(t_win *win);
void		choose_type_draw(t_win *win);
int			x_destroy(void);
void		show_available(int type);
#endif