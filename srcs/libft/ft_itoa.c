/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:44:06 by mscot             #+#    #+#             */
/*   Updated: 2020/11/03 17:44:10 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*result;
	int		n_copy;
	int		n_chars;
	int		flag;

	n_copy = n;
	n_chars = (n < 0) + 2;
	flag = (n > 0) ? 1 : -1;
	while (n_copy /= 10)
		n_chars++;
	if ((result = (char *)malloc(n_chars * sizeof(char))) == NULL)
		return (NULL);
	if (n < 0)
		*result = '-';
	n_chars--;
	result[n_chars--] = '\0';
	if (!n)
		result[0] = 48;
	while (n)
	{
		result[n_chars--] = flag * (n % 10) + (48);
		n /= 10;
	}
	return (result);
}
