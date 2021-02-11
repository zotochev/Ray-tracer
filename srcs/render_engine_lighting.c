/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine_lighting.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:26:18 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:26:35 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int			is_light_ray_blocked(t_vector hit_pos,
								t_scene *scene, t_list *lights)
{
	t_list		*object_list;
	t_light		*light;
	t_roots		roots;
	t_ray		to_light;
	double		length;

	object_list = scene->object_list;
	light = ((t_light *)(lights->content));
	to_light.origin = hit_pos;
	to_light.direction = vector_normalization(
			vector_sub(light->origin, hit_pos));
	length = vector_length(vector_sub(light->origin, hit_pos));
	while (object_list)
	{
		roots = object_intersection(to_light, object_list->content);
		if ((roots.t1 < length || roots.t2 < length)
		&& ((0.00001f < roots.t1 && roots.t1 < INFINITY) ||
			(0.00001f < roots.t2 && roots.t2 < INFINITY)))
			return (1);
		object_list = object_list->next;
	}
	return (0);
}

double		lambert_shading(t_vector hit_pos,
							t_vector hit_normal, t_light *light)
{
	t_vector	l;
	double		l_d;
	double		illumination;
	double		temp;

	l_d = 0;
	l = vector_normalization(vector_sub(light->origin, hit_pos));
	illumination = light->brightness / pow(vector_length(
			vector_sub(light->origin, hit_pos)), 2);
	temp = vector_dot(hit_normal, l);
	l_d += K_D * illumination * ((temp > 0) ? temp : 0);
	return (l_d);
}

double		specular_shading(t_vector hit_pos, t_vector hit_normal,
						t_light *light, t_ray ray)
{
	t_vector	v;
	t_vector	l;
	t_vector	h;
	double		illumination;
	double		temp;

	v = vector_normalization(vector_sub(ray.origin, hit_pos));
	l = vector_normalization(vector_sub(light->origin, hit_pos));
	h = vector_normalization(vector_sum(v, l));
	illumination = light->brightness / pow(
			vector_length(vector_sub(light->origin, hit_pos)), 2);
	temp = vector_dot(hit_normal, h);
	return (K_S * illumination * (temp > 0 ? pow(temp, P) : 0));
}

t_vector	light_calculation(t_vector hit_pos, t_vector hit_normal,
							t_light *light, t_ray ray)
{
	return (vector_mul_by_scal(light->color,
					lambert_shading(hit_pos, hit_normal, light)
					+ specular_shading(hit_pos, hit_normal, light, ray)));
}
