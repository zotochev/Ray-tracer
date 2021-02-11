/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:32:51 by mscot             #+#    #+#             */
/*   Updated: 2020/11/05 17:32:57 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s_joined_len;
	char	*s_joined;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s_joined_len = s1_len + ft_strlen(s2) + 1;
	if ((s_joined = malloc(s_joined_len * sizeof(char))) == NULL)
		return (NULL);
	ft_strlcpy(s_joined, s1, s1_len + 1);
	ft_strlcat(s_joined, s2, s_joined_len);
	return (s_joined);
}
