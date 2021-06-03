#include "../includes/fractol.h"

t_complex	make_complex(double real, double imaginary)
{
	t_complex	name;

	name.r = real;
	name.i = imaginary;
	return (name);
}
