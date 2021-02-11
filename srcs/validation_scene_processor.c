/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_scene_processor.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:35:52 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:36:25 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_line_valid(const char *line)
{
	char	*line_p;

	line_p = (char *)line;
	while (ft_isspace(*line_p))
		line_p++;
	if (line_p[0] == 'R')
		return (is_resolution_valid(line_p));
	else if (line_p[0] == 'A')
		return (is_ambient_valid(line_p));
	else if (line_p[0] == 'c' && line_p[1] != 'y')
		return (is_camera_valid(line_p));
	else if (line_p[0] == 'l')
		return (is_light_valid(line_p));
	else if (line_p[0] == 'p' && line_p[1] == 'l')
		return (is_plain_valid(line_p));
	else if (line_p[0] == 's' && line_p[1] == 'p')
		return (is_sphere_valid(line_p));
	else if (line_p[0] == 's' && line_p[1] == 'q')
		return (is_square_valid(line_p));
	else if (line_p[0] == 'c' && line_p[1] == 'y')
		return (is_cylinder_valid(line_p));
	else if (line_p[0] == 't' && line_p[1] == 'r')
		return (is_triangle_valid(line_p));
	else
		return (0);
}
