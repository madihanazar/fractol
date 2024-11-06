/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazar <mnazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 19:29:55 by mnazar            #+#    #+#             */
/*   Updated: 2024/11/06 20:07:41 by mnazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int init_julia(char *x, char *y, t_fractol *fractol)
{
	fractol->name = "julia";
	if (is_valid(x) || is_valid(y))
		return (0);
	fractol->julia_x = str_to_double(x);
	fractol->julia_y = str_to_double(y);
	return (1);
}
static void	render_pixel(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_length) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
	
void julia(int x, int y, t_fractol *fractol) 
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i  = 0;
	z.x = (scale_val(x, -2, +2, 0, WIDTH) * fractol->zoom) + fractol->shift_x;
	z.y = (scale_val(y, +2, -2, 0, HEIGHT) * fractol->zoom) + fractol->shift_y;
	c.x = fractol->julia_x;
	c.y = fractol->julia_y;
	
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
