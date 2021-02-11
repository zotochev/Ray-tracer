/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:51:08 by mscot             #+#    #+#             */
/*   Updated: 2020/11/05 16:35:31 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (n == 0)
		return (0);
	while (count < n - 1 && (s1[count] == s2[count])
			&& ((s1[count] != '\0') && (s2[count] != '\0')))
		count++;
	return ((unsigned char)(s1[count]) - (unsigned char)(s2[count]));
}
