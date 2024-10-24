/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazar <mnazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:01:45 by mnazar            #+#    #+#             */
/*   Updated: 2024/10/24 19:42:20 by mnazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void malloc_error()
{
    ft_putstr_fd("Error", 1);
    exit(1);
}

void data_init(t_fractol *fractol)
{
	fractol->escape_value = 4; // 2 ^ 2
	fractol->iteration_def= 50; 
}
void fractol_init(t_fractol *fractol)
{
    fractol->mlx_connection = mlx_init();
	if (fractol->mlx_connection == NULL)
        malloc_error(); //to do
    fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH, HEIGHT, fractol->name);
    if (fractol->mlx_window == NULL)
    {
        mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
        free(fractol->mlx_connection);
        malloc_error(); //to do
    }
    fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection, WIDTH, HEIGHT);
    if (fractol->img.img_ptr == NULL)
    {
        mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
        mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
        free(fractol->mlx_connection);
        malloc_error(); //to do
    }
    fractol->img.pixels_ptr = mlx_get_data_addr(fractol->img.img_ptr, &fractol->img.bpp, &fractol->img.line_length, &fractol->img.endian);

	// events to do
    data_init(fractol);
}