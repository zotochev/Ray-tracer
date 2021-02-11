/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <mscot@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 19:28:03 by mscot             #+#    #+#             */
/*   Updated: 2021/02/07 19:28:47 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	get_next_line(int fd, char **line)
{
	int		read_rv;
	char	buf;
	char	tmp_line[1000];
	int		count;

	buf = '\0';
	tmp_line[0] = '\0';
	count = 0;
	while (1)
	{
		if (0 > (read_rv = read(fd, &buf, 1)))
			return (read_rv);
		if (buf != '\n' && read_rv != 0)
			tmp_line[count++] = buf;
		else
		{
			tmp_line[count] = '\0';
			if (NULL == (*line = ft_strdup(tmp_line)))
				return (-1);
			tmp_line[0] = '\0';
			return (read_rv);
		}
	}
}
