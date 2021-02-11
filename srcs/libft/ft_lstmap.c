/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:13:00 by mscot             #+#    #+#             */
/*   Updated: 2020/11/10 12:52:50 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*lst_temp;

	if (lst == NULL)
		return (NULL);
	if ((lst_new = ft_lstnew(f(lst->content))) == NULL)
	{
		ft_lstclear(&lst_new, del);
		return (NULL);
	}
	lst = lst->next;
	while (lst != NULL)
	{
		if ((lst_temp = ft_lstnew(f(lst->content))) == NULL)
		{
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		ft_lstadd_front(&lst_new, lst_temp);
		lst = lst->next;
	}
	return (lst_new);
}
