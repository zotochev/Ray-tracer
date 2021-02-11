/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:44:34 by mscot             #+#    #+#             */
/*   Updated: 2020/11/05 16:34:52 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (0);
	while (((unsigned char *)s1)[count] == ((unsigned char *)s2)[count]
			&& count < (int)n - 1)
		count++;
	return ((int)(((unsigned char *)s1)[count] - ((unsigned char *)s2)[count]));
}
