/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnazar <mnazar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:15:06 by mnazar            #+#    #+#             */
/*   Updated: 2024/11/06 20:05:22 by mnazar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double scale_val(double num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (num - old_min) / (old_max - old_min) + new_min;
}

t_complex sum_complex(t_complex z1, t_complex z2)
{
	t_complex	result;

	result.x = z1.x + z2.x;
	result.y = z1.y + z2.y;
	return (result);
}

t_complex square_complex(t_complex z)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	return (result);
	
}
double	str_to_double(char *s)
{
	double integer_part;
	double fract_part;
	int sign;
	double base;

	base = 1.0;
	integer_part = 0;
	fract_part = 0;
	sign = 1;
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{	
		integer_part = (integer_part * 10) + (*s - '0');
		s++;
	}
	if (*s == '.')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		base *= 10.0;
		fract_part += (*s - '0') / base;
		s++;
	}
	return ((integer_part + fract_part) * sign);
}
int is_valid(char *str)
{
	int	i;
	int val;

	i = 0;
	val = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
		val = 1;
	// printf("%s\n", str);
	// printf("%d\n",val);
	return (val);
}
