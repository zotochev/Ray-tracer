/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:17:09 by mscot             #+#    #+#             */
/*   Updated: 2020/11/04 14:46:32 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_el;

	new_el = NULL;
	if (content == NULL)
		return (NULL);
	if ((new_el = (t_list *)malloc(sizeof(t_list))) == NULL)
	{
		perror("Error\nmemory allocation in function \"ft_lstnew\" failed");
		return (NULL);
	}
	new_el->content = content;
	new_el->next = NULL;
	return (new_el);
}
