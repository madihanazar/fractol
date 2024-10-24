#include "fractol.h"
int main(int ac, char **argv)
{
    t_fractol   fractol;
    if (ac < 2)
        return (print_error("Error: Not enough arguments"));
    fractol.name = argv[1];
    fractol_init(&fractol);
    fractol_render(&fractol);
    mlx_loop(fractol.mlx_connection);
}

static int print_error(char *s)
{
    ft_putstr_fd(s, 1);
    return (1);
}