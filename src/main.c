#include "../includes/fractol.h"

void	choose_case(char *arg, t_win *win)
{
	if (ft_atoi(arg) == 1)
		win->k = init_complex(0, 0.8);
	else if (ft_atoi(arg) == 2)
		win->k = init_complex(0.37, 0.1);
	else if (ft_atoi(arg) == 3)
		win->k = init_complex(0.355, 0.355);
	else if (ft_atoi(arg) == 4)
		win->k = init_complex(-0.54, 0.54);
	else if (ft_atoi(arg) == 5)
		win->k = init_complex(-0.4, -0.59);
	else if (ft_atoi(arg) == 6)
		win->k = init_complex(0.34, -0.5);
	else if (ft_atoi(arg) == 7)
		win->k = init_complex(0.285, 0);
	else if (ft_atoi(arg) == 8)
		win->k = init_complex(-0.8, 0.156);
	else if (ft_atoi(arg) == 9)
		win->k = init_complex(0.285, 0.1);
	else if (ft_atoi(arg) == 10)
		win->k = init_complex(-0.75, 0.11);
	else if (ft_atoi(arg) == 11)
		win->k = init_complex(-1.476, 0);
	else if (ft_atoi(arg) == 12)
		win->k = init_complex(0.355534, -0.337292);
}

void	case_arg_treat(char *arg, t_win *win)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			show_available(4);
		i++;
	}
	if (ft_atoi(arg) > 12)
		show_available(5);
	choose_case(arg, win);
}

void	iteration_arg_treat(char *arg, t_win *win)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			show_available(4);
		i++;
	}
	if (ft_atoi(arg) > 9 && ft_atoi(arg) < 1001)
		win->max_i = ft_atoi(arg);
	else
		show_available(6);
}

int	julia_mandelbrot(int argc, char **argv, t_win *win)
{
	if (!ft_strncmp(argv[1], "help", 5))
		show_available(3);
	else if (!ft_strncmp(argv[1], "Julia", 6))
	{
		if (argc == 3)
			case_arg_treat(argv[2], win);
		else if (argc == 4)
		{
			case_arg_treat(argv[2], win);
			iteration_arg_treat(argv[3], win);
		}
		else if (argc > 4)
			show_available(7);
		julia_init(win);
	}
	else if (!ft_strncmp(argv[1], "Mandelbrot", 11))
	{
		if (argc == 3)
			iteration_arg_treat(argv[2], win);
		else if (argc > 3)
			show_available(7);
		mandelbrot_init(win);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_win	win;

	win.flag_m = 0;
	win.flag_c = 0;
	win.width = 800;
	win.height = 800;
	win.max_i = 50;
	win.k = init_complex(-0.4, 0.6);
	if (argc == 1)
		show_available(1);
	if (argc >= 2)
	{
		if (julia_mandelbrot(argc, argv, &win))
			;
		else if (!ft_strncmp(argv[1], "Mandelbar", 11))
		{
			if (argc == 3)
				iteration_arg_treat(argv[2], &win);
			else if (argc > 3)
				show_available(7);
			mandelbar_init(&win);
		}
		else
			show_available(8);
	}
}
