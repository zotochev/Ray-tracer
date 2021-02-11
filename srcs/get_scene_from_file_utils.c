/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_from_file_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:43:25 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 19:44:06 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_resolution	*get_resolution(const char *line_p,
							t_resolution *validation, int save)
{
	t_resolution	*resolution;

	(void)save;
	if (NULL != validation || !is_line_valid((char *)line_p)
		|| NULL == (resolution = malloc(sizeof(t_resolution))))
	{
		perror("Error\nresolution initialization\n");
		return (NULL);
	}
	line_p = (char *)line_p + 1;
	resolution->width = atoresolution(line_p, 10000);
	line_p += ft_skip_float(line_p);
	resolution->height = atoresolution(line_p, 10000);
	if (0 >= resolution->width || 0 >= resolution->height)
	{
		perror("Error\nresolution should be positive nonzero number\n");
		free(resolution);
		return (NULL);
	}
	return (resolution);
}

t_ambient		*get_ambient(const char *line, t_ambient *validation)
{
	t_ambient	*ambient;
	char		*line_p;

	if (NULL != validation || !is_line_valid((char *)line))
	{
		perror("Error\nambient initialization\n");
		return (NULL);
	}
	if ((NULL == (ambient = malloc(sizeof(t_ambient)))))
	{
		perror("Error\nmemory allocation in \"get_ambient\" failed\n");
		return (NULL);
	}
	line_p = (char *)line + 1;
	ambient->ratio = ft_atof(line_p);
	line_p += ft_skip_float(line_p);
	if ((0 == is_color_valid(ambient->color = ft_atovector(line_p)))
		|| (ambient->ratio < 0 || ambient->ratio > 1.0))
	{
		perror("invalid ambient initialization\n");
		return (NULL);
	}
	return (ambient);
}

t_camera		*get_camera(const char *line)
{
	t_camera	*camera;
	char		*line_p;

	if (!is_line_valid((char *)line))
		return (NULL);
	if (NULL == (camera = malloc(sizeof(t_camera))))
	{
		perror("Error\nmemory allocation in function \"get_camera\" failed");
		return (NULL);
	}
	line_p = (char *)line + 1;
	camera->ray.origin = ft_atovector(line_p);
	line_p += ft_skip_vector(line_p);
	camera->ray.direction = vector_normalization(ft_atovector(line_p));
	line_p += ft_skip_vector(line_p);
	camera->fov = ft_atoi(line_p);
	if ((camera->ray.direction.x == 0 && camera->ray.direction.y == 0
	&& (fabs(camera->ray.direction.z) == 1 || camera->ray.direction.z == 0))
		|| (camera->fov < 0 || camera->fov > 180))
	{
		perror("Error\ncamera fov possible range from 0 to 180\n");
		perror("cam direction should not be [0, 0, 0] or [0, 0, abs(1)]\n");
		return (NULL);
	}
	return (camera);
}

t_light			*get_light(const char *line)
{
	t_light	*light;
	char	*line_p;

	if (!is_line_valid((char *)line))
		return (NULL);
	if (NULL == (light = malloc(sizeof(t_light))))
	{
		perror("Error\nmemory allocation in function \"get_light\" failed");
		return (NULL);
	}
	line_p = (char *)line + 1;
	light->origin = ft_atovector(line_p);
	light->brightness = ft_atof((line_p += ft_skip_vector(line_p)));
	if ((0 == is_color_valid(light->color =
						ft_atovector((line_p += ft_skip_float(line_p)))))
		|| (light->brightness < 0 || light->brightness > 1))
	{
		perror("Error\ninvalid point-light initialisation\n");
		return (NULL);
	}
	return (light);
}
