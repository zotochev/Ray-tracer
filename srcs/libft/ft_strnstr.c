/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:46:32 by mscot             #+#    #+#             */
/*   Updated: 2020/11/05 21:10:45 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hsk_copy;
	size_t	len_count;
	size_t	len_check;
	size_t	len_needle;

	hsk_copy = (char *)haystack;
	len_count = len;
	len_check = ft_strlen(needle);
	len_needle = len_check;
	if (!len_check)
		return ((char *)haystack);
	if (!len)
		return (NULL);
	while ((*hsk_copy != '\0') && (len_count--))
	{
		if ((!ft_strncmp(hsk_copy, (char *)needle, len_needle))
				&& len_check <= len)
			return (hsk_copy);
		hsk_copy++;
		len_check++;
	}
	return (NULL);
}
