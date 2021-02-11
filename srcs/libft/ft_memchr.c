/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:43:23 by mscot             #+#    #+#             */
/*   Updated: 2020/11/01 17:57:05 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_p;
	size_t			count;

	s_p = (unsigned char *)s;
	count = 0;
	while (n > count && s_p[count] != (unsigned char)c)
		count++;
	if (n == count || s_p[count] != (unsigned char)c)
		return (0);
	return ((void *)&(s_p[count]));
}
