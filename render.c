/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazar <mnazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:04:44 by mnazar            #+#    #+#             */
/*   Updated: 2024/11/06 18:18:05 by mnazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void fractol_render(t_fractol *fractol)
{
	int	x;
	int y;

	y = -1;
	if (!ft_strncmp("mandelbrot", fractol->name, 11))
	{
		while (++y < HEIGHT)
		{
			x = -1;
			while (++x < WIDTH)
				mandelbrot(x, y, fractol);
		}
		mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window, fractol->img.img_ptr, 0 ,0);
	}
	else
	{
		while (++y < HEIGHT)
		{
			x = -1;
			while (++x < WIDTH)
				julia(x, y, fractol);
		}
		mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window, fractol->img.img_ptr, 0 ,0);
	}
}