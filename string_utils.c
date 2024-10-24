/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazar <mnazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:01:35 by mnazar            #+#    #+#             */
/*   Updated: 2024/10/24 15:35:32 by mnazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int ft_strncmp(char *s1, char *s2, int n)
{
	if (s1 == NULL || s2 == NULL || n <= 0)
		return (0);
	int i = 0;
	while (i < n && s1[i] && s2[i] && s1[i] == s2[i])
			i++;
	return (s1[i] - s2[i]);
	
}