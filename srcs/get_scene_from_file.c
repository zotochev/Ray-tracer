/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_scene_from_file.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:35:10 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 19:35:39 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	get_object_type(t_object **object, const char *line)
{
	(*object)->type[0] = line[0];
	if (!ft_isspace(line[1]))
		(*object)->type[1] = line[1];
	else
		(*object)->type[1] = '\0';
	(*object)->type[2] = '\0';
}

int		get_object(t_scene **s, const char *l)
{
	void	*r;

	r = "";
	if (l[0] == 'R' && (r = get_resolution(l, (*s)->resolution, (*s)->save)))
		(*s)->resolution = r;
	else if (l[0] == 'A' && (r = get_ambient(l, (*s)->ambient)))
		(*s)->ambient = r;
	else if (l[0] == 'c' && l[1] != 'y')
		ft_lstadd_back(&((*s)->camera_list), (r = ft_lstnew(get_camera(l))));
	else if (l[0] == 'l')
		ft_lstadd_back(&((*s)->light_list), (r = ft_lstnew(get_light(l))));
	else if (l[0] == 'p')
		ft_lstadd_back(&((*s)->object_list), (r = ft_lstnew(get_plain(l))));
	else if (l[0] == 's' && l[1] == 'p')
		ft_lstadd_back(&((*s)->object_list), (r = ft_lstnew(get_sphere(l))));
	else if (l[0] == 's' && l[1] == 'q')
		ft_lstadd_back(&((*s)->object_list), (r = ft_lstnew(get_square(l))));
	else if (l[0] == 'c' && l[1] == 'y')
		ft_lstadd_back(&((*s)->object_list), (r = ft_lstnew(get_cylinder(l))));
	else if (l[0] == 't')
		ft_lstadd_back(&((*s)->object_list), (r = ft_lstnew(get_triangle(l))));
	if (r == NULL || NULL == ft_strchr("RAclpqsct\n#", l[0]))
		return (-1);
	return (1);
}

t_scene	*get_scene_from_file(char *file, int save)
{
	int		fd;
	int		gnl_rv;
	int		get_object_rv;
	char	*line;
	t_scene	*scene;

	get_object_rv = 1;
	if ((0 > (fd = open(file, O_RDONLY)))
			|| (NULL == (scene = new_scene())))
		return (NULL);
	scene->save = save;
	while (0 < (gnl_rv = get_next_line(fd, &line)) && get_object_rv > 0)
	{
		get_object_rv = get_object(&scene, line);
		free(line);
	}
	free(line);
	close(fd);
	if (get_object_rv < 0 || gnl_rv < 0 || 0 == is_scene_valid(scene))
	{
		free_scene(&scene);
		write(1, "check\n", 6);
		while (1)
			;
		exit(1);
	}
	return (scene);
}
