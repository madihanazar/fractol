#include "fractol.h"

static int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (0);
}

void ft_putstr_fd(char *s, int fd)
{
    if (!s || !fd)
		  return;
    write(fd, s, ft_strlen(s));
}