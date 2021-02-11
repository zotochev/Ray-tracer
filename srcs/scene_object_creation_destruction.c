/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_object_creation_destruction.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:32:01 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 20:32:18 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	free_lam(t_lk_at_mtx *lam)
{
	free(lam->lam[0]);
	free(lam->lam[1]);
	free(lam->lam[2]);
	free(lam->lam[3]);
	free(lam->lam);
	free(lam);
}

t_scene	*new_scene(void)
{
	t_scene	*scene;

	if (NULL == (scene = malloc(sizeof(t_scene))))
	{
		perror("Error\nmemory allocation in function \"new_scene\" failed");
		return (NULL);
	}
	scene->camera_list = NULL;
	scene->object_list = NULL;
	scene->light_list = NULL;
	scene->image = NULL;
	scene->resolution = NULL;
	scene->ambient = NULL;
	return (scene);
}

void	free_scene(t_scene **scene)
{
	if ((*scene)->image != NULL)
	{
		image_free_canvas((*scene)->image->canvas);
		free((*scene)->image);
	}
	ft_lstclear(&(*scene)->camera_list, free);
	ft_lstclear(&(*scene)->object_list, free);
	ft_lstclear(&(*scene)->light_list, free);
	if ((*scene)->resolution != NULL)
		free((*scene)->resolution);
	if ((*scene)->ambient != NULL)
		free((*scene)->ambient);
	if (scene != NULL && *scene != NULL)
		free((*scene));
}
