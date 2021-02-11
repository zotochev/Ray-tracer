/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:33:15 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:33:42 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_color_valid(t_vector color)
{
	if ((color.x < 0 || color.y < 0 || color.z < 0)
		|| (color.x > 255 || color.y > 255 || color.z > 255))
	{
		perror("Error\ncolor value should be in a range from 0 to 255\n");
		return (0);
	}
	return (1);
}

int	is_direction_valid(t_vector direction)
{
	if (direction.x == 0 && direction.y == 0 && direction.z == 0)
	{
		perror("Error\ndirection vector should not be [0, 0, 0]\n");
		return (0);
	}
	return (1);
}

int	is_scene_valid(t_scene *scene)
{
	if (!scene->ambient)
		perror("Error\nAmbient was not initialized\n");
	if (!scene->resolution)
		perror("Error\nResolution was not initialized\n");
	if (!scene->camera_list)
		perror("Error\nAt least one camera should be initialized\n");
	if (!scene->ambient || !scene->resolution || !scene->camera_list)
		return (0);
	return (1);
}

int	is_beginning_of_num(const char *line)
{
	return (ft_isdigit(line[0])
			|| ((line[0] == '+' || line[0] == '-') && ft_isdigit(line[1])));
}
