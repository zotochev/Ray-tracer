/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:15:04 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:15:28 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_roots		sphere_intersection(t_ray ray, t_object *sphere)
{
	double		r;
	t_vector	oc;
	double		a;
	double		b;
	double		c;

	r = sphere->radius / 2;
	oc = vector_sub(ray.origin, sphere->origin);
	a = vector_dot(ray.direction, ray.direction);
	b = 2 * vector_dot(oc, ray.direction);
	c = vector_dot(oc, oc) - (r * r);
	return (quadratic_equation(a, b, c));
}

t_vector	sphere_normal(t_object *sphere, t_vector surface_point, t_ray ray)
{
	t_vector	normal;

	normal = vector_normalization(vector_sub(surface_point, sphere->origin));
	if (0 > vector_dot(normal, ray.direction))
		return (normal);
	else
		return (vector_mul_by_scal(normal, -1));
}
