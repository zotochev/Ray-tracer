/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:58:08 by mscot             #+#    #+#             */
/*   Updated: 2020/11/01 18:04:25 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		count;

	count = 0;
	if (dst == src || len == 0)
		return (dst);
	if (dst > src)
	{
		count = len - 1;
		while (count + 1 > 0)
		{
			((char *)dst)[count] = ((char *)src)[count];
			count--;
		}
	}
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}
