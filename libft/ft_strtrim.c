/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:33:47 by mscot             #+#    #+#             */
/*   Updated: 2020/11/05 17:44:37 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_in_set(char c, char *set)
{
	char	*set_p;

	set_p = set;
	while (*set_p)
	{
		if (*set_p == c)
			return (1);
		set_p++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		s_trimmed_len;
	char	*s_p;

	s_p = (char *)s1;
	if (!s1)
		return (NULL);
	while (ft_is_in_set(*s_p, (char *)set))
		s_p++;
	s_trimmed_len = ft_strlen(s_p);
	while (s_trimmed_len && (ft_is_in_set(s_p[s_trimmed_len - 1], (char *)set)))
		s_trimmed_len--;
	s_p = ft_substr(s_p, 0, s_trimmed_len);
	return (s_p);
}
