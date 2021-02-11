/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_processor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:55:03 by mscot             #+#    #+#             */
/*   Updated: 2021/02/08 22:01:00 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <mlx.h>

void	my_mlx_pixel_put(t_image_mlx *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr +
			(y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		w_close(t_data *info)
{
	mlx_destroy_window(info->id, info->window);
	exit(0);
}

void	pixels_to_canvas(t_data *data, t_image *image)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < (int)image->width)
	{
		while (y < (int)image->height)
		{
			my_mlx_pixel_put(&(data->image), x, y, image->canvas[y][x]);
			y++;
		}
		y = 0;
		x++;
	}
}

int		key_hook_processor(int key_hook, t_data *data)
{
	if (key_hook == 48)
	{
		if (data->current_camera->next != NULL)
			data->current_camera = data->current_camera->next;
		else
			data->current_camera = data->scene->camera_list;
		data->scene->image =
				render(data->scene, data->current_camera->content);
		pixels_to_canvas(data, data->scene->image);
		mlx_put_image_to_window(
				data->id, data->window, data->image.img, 0, 0);
	}
	else if (key_hook == 53)
	{
		free_scene(&(data->scene));
		w_close(data);
	}
	return (0);
}

void	print_mlx(t_scene *scene)
{
	t_data	data;

	data.scene = scene;
	data.id = mlx_init();
	check_screen_size(data.id, &scene);
	data.window = mlx_new_window(data.id, scene->resolution->width,
								scene->resolution->height, "miniRT");
	data.image.img = mlx_new_image(data.id, scene->resolution->width,
								scene->resolution->height);
	data.image.addr = mlx_get_data_addr(
			data.image.img,
			&(data.image.bits_per_pixel),
			&(data.image.line_length),
			&(data.image.endian));
	data.current_camera = scene->camera_list;
	mlx_hook(data.window, 17, 0, w_close, &data);
	mlx_key_hook(data.window, key_hook_processor, &data);
	scene->image = render(scene, data.current_camera->content);
	pixels_to_canvas(&data, scene->image);
	mlx_put_image_to_window(data.id, data.window, data.image.img, 0, 0);
	mlx_loop(data.id);
}
