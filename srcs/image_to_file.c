/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_to_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:47:35 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 19:47:57 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	to_file_bmp_add_header(int fd, int width, int height)
{
	char	temp2[54];
	int		count_temp;

	count_temp = 0;
	while (count_temp < 54)
	{
		temp2[count_temp] = 0x00;
		count_temp++;
	}
	temp2[0] = 0x42;
	temp2[1] = 0x4D;
	temp2[10] = 0x36;
	temp2[14] = 0x28;
	temp2[18] = (char)((width & 0x0000FF) >> 0);
	temp2[19] = (char)((width & 0x00FF00) >> 8);
	temp2[20] = (char)((width & 0xFF0000) >> 16);
	temp2[22] = (char)((height & 0x0000FF) >> 0);
	temp2[23] = (char)((height & 0x00FF00) >> 8);
	temp2[24] = (char)((height & 0xFF0000) >> 16);
	temp2[26] = 0x01;
	temp2[28] = 0x18;
	write(fd, temp2, 54);
}

int		to_file_bmp(t_image image, char *file_name)
{
	int		fd;
	int		wth;
	int		hgt;
	char	bgr[3];

	wth = 0;
	hgt = (int)image.height - 1;
	if (-1 == (fd = open(file_name,
						O_WRONLY | O_APPEND | O_TRUNC | O_CREAT, 0644)))
		return (-1);
	to_file_bmp_add_header(fd, (int)image.width, (int)image.height);
	while (hgt >= 0)
	{
		while (wth < (int)image.width)
		{
			bgr[0] = hex_color_to_dec(image.canvas[hgt][wth], BLUE);
			bgr[1] = hex_color_to_dec(image.canvas[hgt][wth], GREEN);
			bgr[2] = hex_color_to_dec(image.canvas[hgt][wth], RED);
			write(fd, bgr, 3);
			wth++;
		}
		wth = 0;
		hgt--;
	}
	return (1);
}

int		to_file_processor(t_scene *scene)
{
	t_list		*camera_list;
	t_camera	*camera;
	int			camera_count;
	char		file_name[10];

	camera_list = scene->camera_list;
	camera_count = 0;
	ft_strlcpy(file_name, "0.bmp", 10);
	while (camera_list != NULL)
	{
		camera = (t_camera *)camera_list->content;
		scene->image = render(scene, camera);
		to_file_bmp(*(scene->image), file_name);
		camera_count++;
		file_name[0] = camera_count + 48;
		camera_list = camera_list->next;
	}
	free_scene(&scene);
	return (1);
}
