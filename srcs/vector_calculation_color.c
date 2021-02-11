/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_calculation_color.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:46:46 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:47:04 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

unsigned int	hex_color_to_dec(unsigned int hex_color, unsigned int color)
{
	if (color == RED)
		return ((hex_color & RED) >> TO_RED);
	else if (color == GREEN)
		return ((hex_color & GREEN) >> TO_GREEN);
	else if (color == BLUE)
		return ((hex_color & BLUE) >> TO_BLUE);
	else
		return (0);
}

t_vector		vector_sum_color(t_vector vector_1, t_vector vector_2)
{
	t_vector	result;

	if (255 < (result.x = vector_1.x + vector_2.x))
		result.x = 255;
	if (255 < (result.y = vector_1.y + vector_2.y))
		result.y = 255;
	if (255 < (result.z = vector_1.z + vector_2.z))
		result.z = 255;
	return (result);
}

t_vector		color_to_vector(unsigned int hex_color)
{
	t_vector	result;

	result.x = (hex_color & RED) >> TO_RED;
	result.y = (hex_color & GREEN) >> TO_GREEN;
	result.z = (hex_color & BLUE) >> TO_BLUE;
	return (result);
}

unsigned int	vector_to_color(t_vector color)
{
	unsigned int	hex_color;
	unsigned int	temp_x;
	unsigned int	temp_y;
	unsigned int	temp_z;

	temp_x = (unsigned int)color.x;
	temp_y = (unsigned int)color.y;
	temp_z = (unsigned int)color.z;
	hex_color = 0;
	hex_color += (255 < temp_x) ? 255 : temp_x << TO_RED;
	hex_color += (255 < temp_y) ? 255 : temp_y << TO_GREEN;
	hex_color += (255 < temp_z) ? 255 : temp_z << TO_BLUE;
	return (hex_color);
}
