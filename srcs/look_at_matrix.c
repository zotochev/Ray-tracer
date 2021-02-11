/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look_at_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:48:28 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 19:48:48 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_lk_at_mtx	*new_look_at_matrix_mem_alloc(void)
{
	t_lk_at_mtx	*lam;

	if (NULL == (lam = malloc(sizeof(t_lk_at_mtx))))
		return (NULL);
	lam->lam = malloc(sizeof(double *) * 4);
	lam->lam[0] = malloc(sizeof(double) * 4);
	lam->lam[1] = malloc(sizeof(double) * 4);
	lam->lam[2] = malloc(sizeof(double) * 4);
	lam->lam[3] = malloc(sizeof(double) * 4);
	if (!lam->lam || !lam->lam[0] || !lam->lam[1]
		|| !lam->lam[2] || !lam->lam[3])
		return (NULL);
	lam->lam[0][3] = 0;
	lam->lam[1][3] = 0;
	lam->lam[2][3] = 0;
	lam->lam[3][3] = 1;
	return (lam);
}

t_lk_at_mtx	*new_look_at_matrix(t_camera *camera)
{
	t_lk_at_mtx	*lam;
	t_vector	forward;
	t_vector	right;
	t_vector	up;

	forward = vector_mul_by_scal(
			vector_normalization(camera->ray.direction), -1);
	right = vector_cross(new_vector(0, 0, 1, 0), forward);
	right = vector_normalization(right);
	up = vector_cross(forward, right);
	lam = new_look_at_matrix_mem_alloc();
	lam->lam[0][0] = right.x;
	lam->lam[0][1] = right.y;
	lam->lam[0][2] = right.z;
	lam->lam[1][0] = up.x;
	lam->lam[1][1] = up.y;
	lam->lam[1][2] = up.z;
	lam->lam[2][0] = forward.x;
	lam->lam[2][1] = forward.y;
	lam->lam[2][2] = forward.z;
	lam->lam[3][0] = camera->ray.origin.x;
	lam->lam[3][1] = camera->ray.origin.y;
	lam->lam[3][2] = camera->ray.origin.z;
	return (lam);
}

t_ray		ray_to_cam(t_lk_at_mtx *lam, t_ray ray)
{
	t_ray	result;

	result.origin = world_to_cam_vec(lam, ray.origin);
	result.direction = world_to_cam_dir(lam, ray.direction);
	return (result);
}

/*
** t_vector	world_to_cam_vec(t_look_at_matrix *lam, t_vector obj)
**
** Function for translation rays origin coordinates from beginning
** of coordinates to camera origin
*/

t_vector	world_to_cam_vec(t_lk_at_mtx *lam, t_vector obj)
{
	t_vector	result;
	double		w;

	result.x = obj.x * lam->lam[0][0] + obj.y * lam->lam[1][0]
			+ obj.z * lam->lam[2][0] + lam->lam[3][0];
	result.y = obj.x * lam->lam[0][1] + obj.y * lam->lam[1][1]
			+ obj.z * lam->lam[2][1] + lam->lam[3][1];
	result.z = obj.x * lam->lam[0][2] + obj.y * lam->lam[1][2]
			+ obj.z * lam->lam[2][2] + lam->lam[3][2];
	w = obj.x * lam->lam[0][3] + obj.y * lam->lam[1][3]
			+ obj.z * lam->lam[2][3] + lam->lam[3][3];
	result.x /= w;
	result.y /= w;
	result.z /= w;
	return (result);
}

/*
** t_vector	world_to_cam_dir(t_look_at_matrix *lam, t_vector obj)
**
** Function for translation rays direction coordinates according with
** camera direction
*/

t_vector	world_to_cam_dir(t_lk_at_mtx *lam, t_vector obj)
{
	t_vector	result;

	result.x =
			obj.x * lam->lam[0][0]
			+ obj.y * lam->lam[1][0]
			+ obj.z * lam->lam[2][0];
	result.y =
			obj.x * lam->lam[0][1]
			+ obj.y * lam->lam[1][1]
			+ obj.z * lam->lam[2][1];
	result.z =
			obj.x * lam->lam[0][2]
			+ obj.y * lam->lam[1][2]
			+ obj.z * lam->lam[2][2];
	return (vector_normalization(result));
}
