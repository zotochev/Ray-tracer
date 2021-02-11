/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:45:53 by mscot             #+#    #+#             */
/*   Updated: 2020/11/01 17:56:27 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;

	count = 0;
	if (dst == NULL && src == NULL)
		return (0);
	while (count < n)
	{
		((char *)dst)[count] = ((char *)src)[count];
		count++;
	}
	return (dst);
}
