/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_from_file_objects.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:40:20 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 19:40:44 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_object	*get_plain(const char *line)
{
	t_object	*plain;
	char		*line_p;

	if (!is_line_valid((char *)line))
		return (NULL);
	if (NULL == (plain = malloc(sizeof(t_object))))
	{
		perror("Error\nmemory allocation in function \"get_plain\" failed");
		return (NULL);
	}
	get_object_type(&plain, line);
	line_p = (char *)line + 2;
	plain->origin = ft_atovector(line_p);
	line_p += ft_skip_vector(line_p);
	plain->direction = vector_normalization(ft_atovector(line_p));
	line_p += ft_skip_vector(line_p);
	if (0 == is_color_valid(plain->color = ft_atovector(line_p))
		|| !is_direction_valid(plain->direction))
	{
		perror("Error\ninvalid plain initialization\n");
		return (NULL);
	}
	return (plain);
}

t_object	*get_sphere(const char *line)
{
	t_object	*sphere;
	char		*line_p;

	if (!is_line_valid((char *)line))
		return (NULL);
	if (NULL == (sphere = malloc(sizeof(t_object))))
	{
		perror("Error\nmemory allocation in function \"get_sphere\" failed");
		return (NULL);
	}
	get_object_type(&sphere, line);
	line_p = (char *)line + 2;
	sphere->origin = ft_atovector(line_p);
	line_p += ft_skip_vector(line_p);
	sphere->radius = ft_atof(line_p);
	line_p += ft_skip_float(line_p);
	if ((0 == is_color_valid(sphere->color = ft_atovector(line_p)))
		|| (sphere->radius <= 0))
	{
		perror("Error\ninvalid sphere initialization\n");
		return (NULL);
	}
	return (sphere);
}

t_object	*get_square(const char *line)
{
	t_object	*square;
	char		*line_p;

	if (!is_line_valid((char *)line))
		return (NULL);
	if (NULL == (square = malloc(sizeof(t_object))))
	{
		perror("Error\nmemory allocation in function \"get_square\" failed");
		return (NULL);
	}
	get_object_type(&square, line);
	square->origin = ft_atovector(
			(line_p = (char *)line + 2));
	line_p += ft_skip_vector(line_p);
	square->direction = vector_normalization(ft_atovector(line_p));
	square->side = ft_atof((line_p += ft_skip_vector(line_p)));
	line_p += ft_skip_float(line_p);
	if ((square->side <= 0) ||
		((!is_color_valid(square->color = ft_atovector(line_p)))
			|| !is_direction_valid(square->direction)))
	{
		perror("Error\ninvalid square initialization\n");
		return (NULL);
	}
	return (square);
}

t_object	*get_cylinder(const char *line)
{
	t_object	*cylinder;
	char		*line_p;

	if (NULL == (cylinder = malloc(sizeof(t_object)))
			|| !is_line_valid((char *)line))
	{
		perror("Error\nfunction \"get_cylinder\" failed");
		return (NULL);
	}
	get_object_type(&cylinder, line);
	cylinder->origin = ft_atovector(
			(line_p = (char *)line + 2));
	line_p += ft_skip_vector(line_p);
	cylinder->direction = vector_normalization(ft_atovector(line_p));
	cylinder->diameter = ft_atof((line_p += ft_skip_vector(line_p)));
	cylinder->height = ft_atof((line_p += ft_skip_float(line_p)));
	line_p += ft_skip_float(line_p);
	if (!is_direction_valid(cylinder->direction)
		|| (0 == is_color_valid(cylinder->color = ft_atovector(line_p)))
		|| (cylinder->diameter <= 0 || cylinder->height <= 0))
	{
		perror("Error\ninvalid cylinder initialization\n");
		return (NULL);
	}
	return (cylinder);
}

t_object	*get_triangle(const char *line)
{
	t_object	*triangle;
	char		*line_p;

	if (!is_line_valid((char *)line))
		return (NULL);
	if (NULL == (triangle = malloc(sizeof(t_object))))
	{
		perror("Error\nmemory allocation in function \"get_triangle\" failed");
		return (NULL);
	}
	get_object_type(&triangle, line);
	triangle->origin = ft_atovector(
			(line_p = (char *)line + 2));
	triangle->point_2 = ft_atovector((line_p += ft_skip_vector(line_p)));
	triangle->point_3 = ft_atovector((line_p += ft_skip_vector(line_p)));
	line_p += ft_skip_vector(line_p);
	if (0 == is_color_valid(triangle->color = ft_atovector(line_p)))
	{
		perror("invalid triangle color\n");
		return (NULL);
	}
	return (triangle);
}
