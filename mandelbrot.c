/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazar <mnazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:26:49 by mnazar            #+#    #+#             */
/*   Updated: 2024/11/06 19:57:52 by mnazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazar <mnazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:04:44 by mnazar            #+#    #+#             */
/*   Updated: 2024/11/03 16:18:24 by mnazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int init_mandelbrot(t_fractol *fractol)
{
	fractol->name = "mandelbrot";
	fractol->julia_x = 0.0;
	fractol->julia_y = 0.0;
	return (1);
}
static void	render_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
	
void mandelbrot(int x, int y, t_fractol *fractol)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i  = 0;
	z.x = 0.0;
	z.y = 0.0;
	c.x = (scale_val(x, -2, +2, 0, WIDTH) * fractol->zoom) + fractol->shift_x;
	c.y = (scale_val(y, +2, -2, 0, HEIGHT) * fractol->zoom) + fractol->shift_y;

	while(i < fractol->iteration_def)
	{
		z = sum_complex(square_complex(z), c);   //equation of mandelbrot
		if ((z.x * z.x) + (z.y * z.y) > fractol->escape_value)
		{
			color = scale_val(i, BLACK, WHITE, 0, fractol->iteration_def);
			render_pixel(x, y, &fractol->img, color);
			return;
		}
		i++;
	}
	render_pixel(x, y, &fractol->img, BLACK);
}
