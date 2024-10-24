#include "fractol.h"

static void malloc_error()
{
    ft_putstr_fd("Error", 1);
    exit(1);
}
void fractol_init(t_fractol *fractol)
{
    if (fractol->mlx_connection == NULL)
        malloc_error(); //to do
    fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH, HEIGHT, fractol->name);
    if (fractol->mlx_window == NULL)
    {
        mlx_destroy_display(fractol->mlx_connection);
        free(fractol->mlx_connection);
        malloc_error(); //to do
    }
    fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection, WIDTH, HEIGHT);
    if (fractol->img.img_ptr == NULL)
    {
        mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
        mlx_destroy_display(fractol->mlx_connection);
        free(fractol->mlx_connection);
        malloc_error(); //to do
    }
    fractol->img.pixels_ptr = (fractol->img.img_ptr, &fractol->img.bpp, &fractol->img.line_length, &fractol->img.endian);
    // events to do
    // data init
}