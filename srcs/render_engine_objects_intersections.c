/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine_objects_intersections.c              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:30:23 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:31:02 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_roots		quadratic_equation(double a, double b, double c)
{
	t_roots		roots;
	double		discriminant;

	roots = fill_roots(INFINITY, INFINITY);
	discriminant = b * b - 4 * a * c;
	if (discriminant >= 0)
	{
		roots.t1 = (-b + sqrt(discriminant)) / (2 * a);
		roots.t2 = (-b - sqrt(discriminant)) / (2 * a);
	}
	return (roots);
}

t_nearest	find_nearest_rt(t_ray ray, t_scene *scene)
{
	t_list		*object;
	t_roots		rts;
	t_nearest	nearest;

	nearest.obj_hit = NULL;
	nearest.dist_min = INFINITY;
	object = scene->object_list;
	while (object != NULL)
	{
		rts = object_intersection(ray, object->content);
		if (rts.t1 < nearest.dist_min && 0.001 <= rts.t1 && rts.t1 < INFINITY)
		{
			nearest.dist_min = rts.t1;
			nearest.obj_hit = object->content;
		}
		if (rts.t2 < nearest.dist_min && 0.001 <= rts.t2 && rts.t2 < INFINITY)
		{
			nearest.dist_min = rts.t2;
			nearest.obj_hit = object->content;
		}
		object = object->next;
	}
	nearest.dist_min *= 0.99;
	return (nearest);
}

t_roots		object_intersection(t_ray ray, t_object *object)
{
	if (object->type[0] == 's' && object->type[1] == 'p')
		return (sphere_intersection(ray, object));
	if (object->type[0] == 'p' && object->type[1] == 'l')
		return (plane_intersection(ray, object));
	if (object->type[0] == 'c' && object->type[1] == 'y')
		return (cylinder_intersection(ray, object));
	if (object->type[0] == 't' && object->type[1] == 'r')
		return (triangle_intersection(ray, object));
	if (object->type[0] == 's' && object->type[1] == 'q')
		return (square_intersection(ray, object));
	return (fill_roots(INFINITY, INFINITY));
}

t_vector	object_normal(t_vector hit_point, t_object *object, t_ray ray)
{
	if (object->type[0] == 's' && object->type[1] == 'p')
		return (sphere_normal(object, hit_point, ray));
	if (object->type[0] == 'p' && object->type[1] == 'l')
		return (plane_normal(object, hit_point, ray));
	if (object->type[0] == 'c' && object->type[1] == 'y')
		return (cylinder_normal(object, hit_point, ray));
	if (object->type[0] == 't' && object->type[1] == 'r')
		return (triangle_normal(object, hit_point, ray));
	if (object->type[0] == 's' && object->type[1] == 'q')
		return (square_normal(object, hit_point, ray));
	return (new_vector(0, 1, 0, 0));
}
