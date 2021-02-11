/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_engine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:21:43 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:22:01 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void		render_processor(t_scene *scene, int save)
{
	if (save)
		to_file_processor(scene);
	else
		print_mlx(scene);
}

t_image		*render(t_scene *scene, t_camera *camera)
{
	int			x;
	int			y;
	t_lk_at_mtx	*lam;
	t_ray		ray;

	x = 0;
	y = 0;
	lam = new_look_at_matrix(camera);
	while (y < scene->resolution->height)
	{
		while (x < scene->resolution->width)
		{
			ray = ray_to_cam(lam, new_ray(x, y, camera, scene));
			scene->image->canvas[y][x] = vector_to_color(
					ray_trace(ray, scene));
			x++;
		}
		x = 0;
		y++;
		ft_putnbr_fd(y * 100 / scene->resolution->height, 1);
		ft_putchar_fd('\r', 1);
	}
	ft_putstr_fd("Rendering is complite\n", 1);
	free_lam(lam);
	return (scene->image);
}

t_vector	ray_trace(t_ray ray, t_scene *scene)
{
	t_vector	color;
	t_nearest	nrst;
	t_vector	hit_pos;
	t_vector	hit_normal;
	t_list		*lights;

	lights = scene->light_list;
	nrst = find_nearest_rt(ray, scene);
	color = new_vector(35, 35, 35, 0);
	if (nrst.obj_hit != NULL)
	{
		hit_pos = vector_sum(ray.origin, vector_mul_by_scal(
				ray.direction, nrst.dist_min));
		hit_normal = vector_normalization(object_normal(
				hit_pos, nrst.obj_hit, ray));
		color = vector_mul_by_scal(nrst.obj_hit->color, scene->ambient->ratio);
		while (lights != NULL)
		{
			if (!is_light_ray_blocked(hit_pos, scene, lights))
				color = vector_sum_color(color, light_calculation(hit_pos,
										hit_normal, lights->content, ray));
			lights = lights->next;
		}
	}
	return (color);
}
