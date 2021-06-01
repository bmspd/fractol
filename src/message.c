#include "../includes/fractol.h"

static void	big_message(void)
{
	printf("These are available fractals:\n[1]: Julia\n[2]:"
		   " Mandelbrot\n[3]: Mandelbar\nKeep an eye on the register!\n");
	printf("Moreover, if you want some variety:\n"
		"./fractol \"name\" \"number of Julia's representation case\"\n"
		"./fractol \"name\" \"number of Julia's representation case\""
		" \"iterations\"\n");
	printf("case 1: k = 0 + 0.8i\n"
		"case 2: k = 0.37 + 0.1i\n"
		"case 3: k = 0.355 + 0.355i\n"
		"case 4: k = -0.54 + 0.54i\n"
		"case 5: k = -0.4 + -0.59i\n"
		"case 6: k = 0.34 + -0.05i\n"
		"case 7: k = 0.285 + 0i\n"
		"case 8: k = -0.8 + 0.156i\n"
		"case 9: k = 0.285 + 0.1i\n"
		"case 10: k = -0.75 + 0.11i\n"
		"case 11: k = -1.476 + 0i\n"
		"case 12: k = 0.355534 + -0.337292i\n"
		"Mandelbrot and Mandelbar sets have only \"iteration\" option\n");
}

void	show_available(int type)
{
	if (type == 1)
		printf("You forgot to put fractal's name as argument!\n");
	if (type == 2)
		printf("It seems that you put wrong argument!\n");
	if (type == 3)
		big_message();
	if (type == 4)
		printf("This argument consists only of digits!!!\n");
	if (type == 5)
		printf("There is only 12 cases to choose!!!\n");
	if (type == 6)
		printf("Available iteration's area: [10; 1000]\nOptimal number: 50!\n"
			   "This was made only for visual understanding!\n");
	if (type == 7)
		printf("Too much arguments where inputted!!!!\n");
	if (type == 8)
		printf("These are available fractals:\n[1]: Julia\n[2]:"
			   " Mandelbrot\n[3]: Mandelbar\nKeep an eye on the register!\n");
	printf("-------------------------------\n");
	exit(0);
}
