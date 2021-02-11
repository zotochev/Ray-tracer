/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:52:21 by mscot             #+#    #+#             */
/*   Updated: 2020/11/01 17:52:27 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	count;
	int	c_idx;

	count = 0;
	c_idx = -1;
	if ((char)c == '\0')
		return ((char *)&(s[ft_strlen(s)]));
	while (s[count] != '\0')
	{
		if (s[count] == c)
			c_idx = count;
		count++;
	}
	if (c_idx != -1)
		return ((char *)&s[c_idx]);
	else
		return (0);
}
