# ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "minilibx/mlx.h"

#define HEIGHT 800
#define WIDTH 800

#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

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

	double escape_value; //hypotenuse
	int		iteration_def;
	double	shift_x;
	double	shift_y;
	double  zoom;
	double  julia_x;
	double julia_y;
}               t_fractol;

typedef struct s_complex
{
	double x;   //real
	double y;   //imaginary
}			t_complex;


// FUNCTIONS
void ft_putstr_fd(char *s, int fd);

void fractol_init(t_fractol *fractol);
int ft_strncmp(char *s1, char *s2, int n);
void fractol_render(t_fractol *fractol);
double scale_val(double unscaled_num, double new_min, double new_max, double old_min, double old_max);
t_complex sum_complex(t_complex z1, t_complex z2);
t_complex square_complex(t_complex z);
void data_init(t_fractol *fractol);
void events_init(t_fractol *fractol);
// hooks
int key_handle(int key, t_fractol *fractol);
int mouse_handle(int button, int x, int y, t_fractol *fractol);
int close_handle(t_fractol *fractol);
double	str_to_double(char *s);

void mandelbrot(int x, int y, t_fractol *fractol);
void julia(int x, int y, t_fractol *fractol);
int init_mandelbrot(t_fractol *fractol);
int init_julia(char *x, char *y, t_fractol *fractol);
int is_valid(char *str);

#endif