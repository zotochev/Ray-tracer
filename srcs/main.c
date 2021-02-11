/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:52:20 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 19:52:55 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

/*
**	main
**
**	Arguments
**		argv[1]	-	file with .rt extension containing scene description
**		argv[2]	-	"--save" key implements saving of the rendered scene
**					to file with .bmp extension ("--save" is optional argument)
**
**	Description
** 		function calls scene parser. After parsing a scene it pass it to
**		render processor for rendering
*/

int	main(int argc, char **argv)
{
	int		save;
	t_scene	*scene;

	save = 0;
	if (argc == 2 || argc == 3)
	{
		if (argc == 3 && 0 == (save = (0 == ft_strncmp(argv[2], "--save", 6))))
		{
			perror("ERROR\nwrong 2nd argument (only \"--save\")\n");
			return (1);
		}
		scene = get_scene_from_file(argv[1], save);
		if (NULL == scene
				|| NULL == (scene->image = image_new(scene->resolution->width,
										scene->resolution->height)))
			return (1);
		render_processor(scene, save);
	}
	else
	{
		perror("ERROR\nwrong number of arguments\n");
		return (1);
	}
	return (0);
}
