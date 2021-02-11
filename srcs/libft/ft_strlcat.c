/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:49:22 by mscot             #+#    #+#             */
/*   Updated: 2020/11/01 17:49:36 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	count;

	count = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while ((src[count] != '\0') && (dstsize > dst_len + count + 1))
	{
		dst[dst_len + count] = src[count];
		count++;
	}
	if ((dstsize != 0))
		dst[dst_len + count] = '\0';
	if (dst_len < dstsize)
		return (dst_len + src_len);
	else
		return (src_len + dstsize);
}
