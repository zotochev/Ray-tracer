/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:08:18 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:08:56 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_vector	square_get_vertex_1(t_object *square, t_vector up,
							t_vector right, int ratio)
{
	t_vector	point;

	point = vector_sum(
			square->origin,
			vector_sum(
					vector_mul_by_scal(
							up, square->side * ratio / 2),
					vector_mul_by_scal(
							right, square->side * ratio / 2)));
	return (point);
}

t_vector	square_get_vertex_2(t_object *square, t_vector up,
							t_vector right, int ratio)
{
	t_vector	point;

	point = vector_sum(
			square->origin,
			vector_sum(
					vector_mul_by_scal(
							up, square->side * ratio / 2),
					vector_mul_by_scal(
							right, -square->side * ratio / 2)));
	return (point);
}

t_object	square_get_vertexes(t_ray ray, t_object *square)
{
	t_object	triangle;
	t_vector	normal;
	t_vector	sky;
	t_vector	right;
	t_vector	up;

	normal = square->direction;
	if (0 > (vector_dot(ray.direction, square->direction)))
		normal = vector_mul_by_scal(square->direction, -1);
	sky = (fabs(normal.z) != 1) ? new_vector(0, 0, 1, 0) :
			new_vector(0, 1, 0, 0);
	right = vector_normalization(vector_cross(normal, sky));
	up = vector_cross(right, normal);
	triangle.origin = square_get_vertex_1(square, up, right, 1);
	triangle.direction = square_get_vertex_2(square, up, right, -1);
	triangle.point_2 = square_get_vertex_2(square, up, right, 1);
	triangle.point_3 = square_get_vertex_1(square, up, right, -1);
	return (triangle);
}

t_roots		square_intersection(t_ray ray, t_object *square)
{
	t_object	triangle;
	t_roots		roots;
	t_roots		dist;
	t_ray		tr_vec;
	t_vector	hit_vec;

	roots = plane_intersection(ray, square);
	if (roots.t1 != INFINITY)
	{
		triangle = square_get_vertexes(ray, square);
		tr_vec.origin = vector_sub(triangle.direction, triangle.origin);
		tr_vec.direction = vector_sub(triangle.point_2, triangle.origin);
		hit_vec = vector_sub(vector_sum(ray.origin,
										vector_mul_by_scal(
				ray.direction, roots.t1)), triangle.origin);
		dist.t1 = vector_dot(
				vector_normalization(tr_vec.origin), hit_vec);
		dist.t2 = vector_dot(
				vector_normalization(tr_vec.direction), hit_vec);
		if (0.0 <= dist.t1 && dist.t1 <= vector_length(tr_vec.origin)
			&& 0.0 <= dist.t2 && dist.t2 <= vector_length(tr_vec.direction))
			return (roots);
	}
	return (fill_roots(INFINITY, INFINITY));
}

t_vector	square_normal(t_object *square, t_vector surface_point, t_ray ray)
{
	return (plane_normal(square, surface_point, ray));
}
