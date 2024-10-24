# ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"

#define HEIGHT 800
#define WIDTH 800

typedef struct s_img
{
    int   bpp;
    void *img_ptr;
    char *pixels_ptr;
    int endian;
    int		line_length;
}           t_img;

typedef struct s_fractol
{
    char *name;
    void *mlx_connection;  //mlx_init()
    void *mlx_window;     //mlx_window()
    t_img img;
}               t_fractol;

// FUNCTIONS
void ft_putstr_fd(char *s, int fd);

void fractol_init(t_fractol *fractol)


#endif