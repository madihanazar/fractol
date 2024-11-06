/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazar <mnazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 21:02:43 by mnazar            #+#    #+#             */
/*   Updated: 2024/11/03 20:35:10 by mnazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int close_handle(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx_connection, fractol->img.img_ptr);
	mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
	free(fractol->mlx_connection);
	exit(1);
}
int	key_handle(int key, t_fractol *fractol)
{
	if (key == 53)  //escape is 53
		close_handle(fractol);
	if (key == 123) // Left arrow key on macOS
		fractol->shift_x += (0.5 * fractol->zoom);	//adjusted acc to how zoomed in u are
	else if (key == 124) // Right arrow key on macOS
		fractol->shift_x -= (0.5 * fractol->zoom);	
	else if (key == 126) // Up arrow key on macOS
		fractol->shift_y -= (0.5 * fractol->zoom);	
	else if (key == 125) // Down arrow keoy on macOS
		fractol->shift_y += (0.5 * fractol->zoom);	
	else if (key == 24) // '+' key on macOS
		fractol->iteration_def += 10;
	else if (key == 27) // '-' key on macOS	
		fractol->iteration_def -= 10;
	fractol_render(fractol);
	return 0;
}

int mouse_handle(int button, int x, int y, t_fractol *fractol)
{
	mlx_mouse_get_pos(fractol->mlx_window, &x, &y);  //get current mouse position
	if (button == 4)
	{	
		fractol->zoom *= 1.25;
		// if (fractol->zoom > 100.0)
		// 	fractol->zoom = 100.0;
		//printf("Zoom In: %f\n", fractol->zoom);
	}
	else if (button == 5)
	{
        fractol->zoom /= 1.25;
		// if (fractol->zoom < 0.1)
		// 	fractol->zoom = 0.1;
        //printf("Zoom Out: %f\n", fractol->zoom);  // Debug print
    }
	fractol_render(fractol);
	return (0);
}
