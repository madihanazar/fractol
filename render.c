/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazar <mnazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:04:44 by mnazar            #+#    #+#             */
/*   Updated: 2024/10/24 18:49:45 by mnazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
	
static void handle_pixel(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i  = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = scale_val(x, -2, +2, 0, WIDTH);
	c.y = scale_val(y, +2, -2, 0, HEIGHT);

	while(i < fractol->iteration_def)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = scale_val(i, BLACK, WHITE, 0, fractol->iteration_def);
			my_pixel_put(x, y, &fractol->img, color);
			return;
		}
		i++;
	}
	my_pixel_put(x, y, &fractol->img, PSYCHEDELIC_PURPLE);
}
void fractol_render(t_fractol *fractol)
{
	int	x;
	int y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, fractol);
		
	}
	mlx_put_image_to_window(fractol->mlx_connection, fractol->mlx_window, fractol->img.img_ptr, 0 ,0);
}
