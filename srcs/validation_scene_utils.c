/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_scene_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:37:14 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:37:32 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	is_vector_valid(char *line_p)
{
	while (ft_isspace(*line_p))
		line_p++;
	if (!(is_beginning_of_num(line_p)))
		return (0);
	line_p += ft_skip_float(line_p);
	while (ft_isspace(*line_p))
		line_p++;
	if (*line_p != ',')
		return (0);
	line_p++;
	while (ft_isspace(*line_p))
		line_p++;
	if (!(is_beginning_of_num(line_p)))
		return (0);
	line_p += ft_skip_float(line_p);
	while (ft_isspace(*line_p))
		line_p++;
	if (*line_p != ',')
		return (0);
	line_p++;
	while (ft_isspace(*line_p))
		line_p++;
	return (is_beginning_of_num(line_p));
}

int	is_resolution_valid(char *resolution)
{
	resolution++;
	if (!ft_isspace(*resolution))
		return (0);
	while (ft_isspace(*resolution))
		resolution++;
	if (!ft_isdigit(*resolution))
		return (0);
	resolution += ft_skip_float(resolution);
	while (ft_isspace(*resolution))
		resolution++;
	if (!ft_isdigit(*resolution))
		return (0);
	resolution += ft_skip_float(resolution);
	while (ft_isspace(*resolution))
		resolution++;
	return (*resolution == '\0');
}

int	is_ambient_valid(char *ambient)
{
	ambient++;
	if (!ft_isspace(*ambient))
		return (0);
	while (ft_isspace(*ambient))
		ambient++;
	if (!(is_beginning_of_num(ambient)))
		return (0);
	ambient += ft_skip_float(ambient);
	while (ft_isspace(*ambient))
		ambient++;
	if (!(is_beginning_of_num(ambient)))
		return (0);
	if (!is_vector_valid(ambient))
		return (0);
	ambient += ft_skip_vector(ambient);
	while (ft_isspace(*ambient))
		ambient++;
	return (*ambient == '\0');
}

int	is_camera_valid(char *camera)
{
	if (!ft_isspace(*++camera))
		return (0);
	while (ft_isspace(*camera))
		camera++;
	if (!(is_beginning_of_num(camera)))
		return (0);
	if (!is_vector_valid(camera))
		return (0);
	camera += ft_skip_vector(camera);
	while (ft_isspace(*camera))
		camera++;
	if (!(is_beginning_of_num(camera)))
		return (0);
	if (!is_vector_valid(camera))
		return (0);
	camera += ft_skip_vector(camera);
	while (ft_isspace(*camera))
		camera++;
	if (!(is_beginning_of_num(camera)))
		return (0);
	camera += ft_skip_float(camera);
	while (ft_isspace(*camera))
		camera++;
	return (*camera == '\0');
}

int	is_light_valid(char *light)
{
	if (!ft_isspace(*++light))
		return (0);
	while (ft_isspace(*light))
		light++;
	if (!(ft_isdigit(*light) || *light == '+' || *light == '-'))
		return (0);
	if (!is_vector_valid(light))
		return (0);
	light += ft_skip_vector(light);
	while (ft_isspace(*light))
		light++;
	if (!(ft_isdigit(*light) || *light == '+' || *light == '-'))
		return (0);
	light += ft_skip_float(light);
	while (ft_isspace(*light))
		light++;
	if (!(ft_isdigit(*light) || *light == '+' || *light == '-'))
		return (0);
	if (!is_vector_valid(light))
		return (0);
	light += ft_skip_vector(light);
	while (ft_isspace(*light))
		light++;
	return (*light == '\0');
}
