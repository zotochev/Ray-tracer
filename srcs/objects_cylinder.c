/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:13:02 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:13:29 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_cylinder_calc	new_cylinder_calc(t_ray ray, t_object *cylinder)
{
	t_cylinder_calc	cyl;

	cyl.ca = vector_mul_by_scal(cylinder->direction, cylinder->height);
	cyl.ca = vector_mul_by_scal(cylinder->direction, cylinder->height);
	cyl.oc = vector_sub(ray.origin, cylinder->origin);
	cyl.caca = vector_dot(cyl.ca, cyl.ca);
	cyl.card = vector_dot(cyl.ca, ray.direction);
	cyl.caoc = vector_dot(cyl.ca, cyl.oc);
	cyl.a = cyl.caca - cyl.card * cyl.card;
	cyl.b = cyl.caca * vector_dot(cyl.oc, ray.direction)
			- cyl.caoc * cyl.card;
	cyl.c = cyl.caca * vector_dot(cyl.oc, cyl.oc)
			- cyl.caoc * cyl.caoc - pow(cylinder->diameter / 2, 2) * cyl.caca;
	cyl.h = cyl.b * cyl.b - cyl.a * cyl.c;
	return (cyl);
}

t_roots			cylinder_intersection(t_ray ray, t_object *cylinder)
{
	double			t1;
	double			t2;
	double			y1;
	double			y2;
	t_cylinder_calc	cyl;

	cyl = new_cylinder_calc(ray, cylinder);
	if (cyl.h < 0.0)
		return (fill_roots(INFINITY, INFINITY));
	cyl.h = sqrt(cyl.h);
	t1 = (-cyl.b - cyl.h) / cyl.a;
	t2 = (-cyl.b + cyl.h) / cyl.a;
	y1 = cyl.caoc + t1 * cyl.card;
	y2 = cyl.caoc + t2 * cyl.card;
	if ((y1 > 0.0 && y1 < cyl.caca))
		return (fill_roots(t1, t2));
	if ((y2 > 0.0 && y2 < cyl.caca))
		return (fill_roots(t2, t2));
	return (fill_roots(INFINITY, INFINITY));
}

t_vector		cylinder_normal(t_object *cylinder,
								t_vector surface_point, t_ray ray)
{
	t_vector	to_zero;
	t_vector	to_point;
	t_vector	normal;
	double		dot_;

	(void)ray;
	to_zero = vector_sub(surface_point, cylinder->origin);
	dot_ = vector_dot(cylinder->direction, to_zero);
	to_point = vector_mul_by_scal(cylinder->direction, dot_);
	normal = vector_sub(to_zero, to_point);
	return (vector_normalization(normal));
}
