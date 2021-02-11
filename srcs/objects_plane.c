/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:13:58 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:14:25 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_roots		plane_intersection(t_ray ray, t_object *plane)
{
	t_roots		roots;
	double		dnm;
	double		dist;
	t_vector	p_l_vector;

	dist = -1000;
	dnm = vector_dot(plane->direction, ray.direction);
	roots = fill_roots(INFINITY, INFINITY);
	if (dnm > 0.0001f || dnm < 0.0001f)
	{
		p_l_vector = vector_sub(plane->origin, ray.origin);
		dist = vector_dot(p_l_vector, plane->direction) / dnm;
	}
	if (dist > 0.0001f)
	{
		roots.t1 = dist;
		roots.t2 = dist;
	}
	return (roots);
}

t_vector	plane_normal(t_object *plane, t_vector surface_point, t_ray ray)
{
	(void)surface_point;
	if (0 < vector_dot(ray.direction, plane->direction))
		return (vector_mul_by_scal(plane->direction, -1));
	else
		return (plane->direction);
}
