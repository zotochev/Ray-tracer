/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_check_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:55:03 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 19:57:52 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <mlx.h>

void	check_screen_size(void *mlx_ptr, t_scene **scene)
{
	int	width;
	int height;

	mlx_get_screen_size(mlx_ptr, &width, &height);
	if (width < (*scene)->resolution->width)
	{
		(*scene)->resolution->width = width;
		(*scene)->image->width = width;
	}
	if (height < (*scene)->resolution->height)
	{
		(*scene)->resolution->height = height;
		(*scene)->image->height = height;
	}
}
