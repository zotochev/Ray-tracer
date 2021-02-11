/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine_objects_creation.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@students.21-school.ru>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:28:10 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:28:36 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_ray		new_ray(double x, double y, t_camera *camera, t_scene *scene)
{
	t_ray	ray;
	double	scale;
	double	image_aspect_ratio;
	double	width;
	double	height;

	scale = tan(((double)camera->fov * (M_PI / 180)) / 2);
	image_aspect_ratio = (double)scene->resolution->width
						/ (double)scene->resolution->height;
	width = (double)scene->resolution->width;
	height = (double)scene->resolution->height;
	ray.origin.x = 0;
	ray.origin.y = 0;
	ray.origin.z = 0;
	ray.direction.x = (2 * (x + 0.5) / width - 1) * scale * image_aspect_ratio;
	ray.direction.y = -(2 * (y + 0.5) / height - 1) * scale;
	ray.direction.z = -1;
	ray.direction = vector_normalization(ray.direction);
	return (ray);
}

t_vector	new_vector(double x, double y, double z, int norm)
{
	t_vector	vector;

	vector.x = x;
	vector.y = y;
	vector.z = z;
	if (norm)
		vector = vector_normalization(vector);
	return (vector);
}

t_roots		fill_roots(double t1, double t2)
{
	t_roots	roots;

	roots.t1 = t1;
	roots.t2 = t2;
	return (roots);
}
