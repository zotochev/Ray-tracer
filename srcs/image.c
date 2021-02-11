/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:45:02 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 19:45:31 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

t_image			*image_new(long width, long height)
{
	t_image			*new;

	if (NULL == (new = malloc(sizeof(t_image))))
		return (NULL);
	new->width = width;
	new->height = height;
	new->canvas = image_pixels(height, width);
	new->image_size = 54 + (width * height * 4);
	return (new);
}

void			image_free_canvas(unsigned int **canvas)
{
	int count;

	count = 0;
	if (NULL != canvas)
	{
		while (canvas[count])
		{
			free(canvas[count]);
			count++;
		}
		free(canvas);
	}
}

unsigned int	**image_pixels(unsigned int height, unsigned int width)
{
	unsigned int	count;
	unsigned int	**canvas;

	count = 0;
	if (height == 0 || width == 0)
	{
		perror("Error\nWrong image size\n");
		return (NULL);
	}
	if (NULL == (canvas = (unsigned int **)malloc(
			sizeof(unsigned int *) * (height + 1))))
		return (NULL);
	while (count < height)
	{
		canvas[count] = (unsigned int *)malloc(sizeof(unsigned int) * width);
		if (canvas[count] == NULL)
		{
			image_free_canvas(canvas);
			return (NULL);
		}
		count++;
	}
	canvas[count] = NULL;
	return (canvas);
}
