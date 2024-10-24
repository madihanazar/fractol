/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazar <mnazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:01:49 by mnazar            #+#    #+#             */
/*   Updated: 2024/10/24 18:04:41 by mnazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int check_args(int ac, char **argv)
{
	if (ac < 2)
	{
		ft_putstr_fd("For Mandelbrot set, type : mandelbrot\n", 1);
		ft_putstr_fd("For Julia set, type julia OR julia x OR julia x y", 1);
	}
	else if (ac == 2)
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 11))
			return (1);
		else if (!ft_strncmp(argv[1], "julia", 6))
			return (1);
	}
	else if (ac == 3)
	{
		if (!ft_strncmp(argv[1], "julia", 6))
			return (1);
	}
	else if (ac == 4)
	{
		if (!ft_strncmp(argv[1], "julia", 6))
			return (1);
	}
	return (0);
}
int main(int ac, char **argv)
{
    t_fractol   fractol;
	if (!check_args(ac, argv))
		exit(1);
    fractol.name = argv[1];
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
