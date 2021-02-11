/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:50:14 by mscot             #+#    #+#             */
/*   Updated: 2020/11/05 11:28:28 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;

	count = 0;
	if (!(dst || src))
		return (0);
	while (dstsize != 0 && (dstsize - 1 > count) && (src[count] != '\0'))
	{
		dst[count] = src[count];
		count++;
	}
	if (dstsize != 0)
		dst[count] = '\0';
	return (ft_strlen(src));
}
