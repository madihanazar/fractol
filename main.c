/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazar <mnazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:01:49 by mnazar            #+#    #+#             */
/*   Updated: 2024/11/06 19:58:17 by mnazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int print_error()
{
	ft_putstr_fd("For Mandelbrot set, type : mandelbrot\n", 1);
	ft_putstr_fd("For Julia set, type julia OR julia x OR julia x y\n", 1);
	return (0);
}
static int check_args(int ac, char **argv, t_fractol *fractol)
{
	if (ac < 2)
		return (print_error());
	else if (ac == 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 11))
			return (init_mandelbrot(fractol));
		else if (!ft_strncmp(argv[1], "julia", 6))
			return (init_julia("0", "0", fractol));
	}
	else if (ac == 3)
	{
		if (!ft_strncmp(argv[1], "julia", 6))
			return (init_julia(argv[2], "0", fractol));
	}
	else if (ac == 4)
	{
		if (!ft_strncmp(argv[1], "julia", 6))
			return (init_julia(argv[2], argv[3], fractol));
	}
	return (print_error());
}
int main(int ac, char **argv)
{
    t_fractol   fractol;
	if (!check_args(ac, argv, &fractol))
		exit(1);
    //fractol.name = argv[1];
	// fractol.julia_x = str_to_double(argv[2]);
	// fractol.julia_y = str_to_double(argv[3]);
    fractol_init(&fractol);
    fractol_render(&fractol);
    mlx_loop(fractol.mlx_connection);
}

// static int print_error()
// {
//     ft_putstr_fd("For Mandelbrot set, type : mandelbrot\n", 1);
// 	ft_putstr_fd("For Julia set, type julia OR julia x OR julia x y", 1);
// 	return (0);
// }
