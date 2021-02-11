/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:48:36 by mscot             #+#    #+#             */
/*   Updated: 2020/11/02 15:55:23 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		s1_len;

	s1_len = ft_strlen(s1) + 1;
	if ((s2 = (char *)malloc((s1_len) * sizeof(char))) == NULL)
		return (NULL);
	if (s2)
		ft_strlcpy(s2, s1, s1_len);
	return (s2);
}
