/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_triangle.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:19:09 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:19:44 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_triangle_calc	new_triangle_calc(t_ray ray, t_object *triangle)
{
	t_triangle_calc tri;

	tri.vec_1_to_0 = vector_sub(triangle->point_2, triangle->origin);
	tri.vec_2_to_0 = vector_sub(triangle->point_3, triangle->origin);
	tri.rov_0 = vector_sub(ray.origin, triangle->origin);
	tri.n = vector_cross(tri.vec_1_to_0, tri.vec_2_to_0);
	tri.q = vector_cross(tri.rov_0, ray.direction);
	tri.d = 1.0f / vector_dot(ray.direction, tri.n);
	tri.u = tri.d * vector_dot(
			vector_mul_by_scal(tri.q, -1), tri.vec_2_to_0);
	tri.v = tri.d * vector_dot(tri.q, tri.vec_1_to_0);
	tri.t = tri.d * vector_dot(
			vector_mul_by_scal(tri.n, -1), tri.rov_0);
	return (tri);
}

t_roots			triangle_intersection(t_ray ray, t_object *triangle)
{
	t_roots			roots;
	t_triangle_calc	tri;

	tri = new_triangle_calc(ray, triangle);
	roots = fill_roots(INFINITY, INFINITY);
	if (!(tri.u < 0.0f || tri.u > 1.0f
		|| tri.v < 0.0f || (tri.u + tri.v) > 1.0f))
	{
		roots.t1 = tri.t;
		roots.t2 = tri.t;
	}
	return (roots);
}

t_vector		triangle_normal(t_object *triangle,
						t_vector surface_point, t_ray ray)
{
	t_vector	vec_1_to_0;
	t_vector	vec_2_to_0;

	vec_1_to_0 = vector_sub(triangle->point_2, triangle->origin);
	vec_2_to_0 = vector_sub(triangle->point_3, triangle->origin);
	triangle->direction = vector_cross(vec_1_to_0, vec_2_to_0);
	return (plane_normal(triangle, surface_point, ray));
}
