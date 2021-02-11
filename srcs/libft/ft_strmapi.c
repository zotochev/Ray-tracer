/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:33:18 by mscot             #+#    #+#             */
/*   Updated: 2020/11/10 15:33:30 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	int				s_len;
	char			*result;

	count = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if ((result = (char *)malloc((s_len + 1) * sizeof(char))) == NULL)
		return (NULL);
	while (s[count])
	{
		result[count] = f(count, s[count]);
		count++;
	}
	result[count] = '\0';
	return (result);
}
