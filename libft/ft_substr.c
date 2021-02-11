/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:59:11 by mscot             #+#    #+#             */
/*   Updated: 2020/11/14 12:39:16 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s_p;
	char			*ss;
	char			*ss_p;
	unsigned int	s_len;

	s_p = (char *)s;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
	{
		if ((ss = (char *)malloc(sizeof(char))) == NULL)
			return (NULL);
		*ss = '\0';
		return (ss);
	}
	if ((ss = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	ss_p = ss;
	while (start--)
		s_p++;
	while (len--)
		*ss_p++ = *s_p++;
	*ss_p++ = '\0';
	return (ss);
}
