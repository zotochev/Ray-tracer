/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:17:15 by mscot             #+#    #+#             */
/*   Updated: 2020/11/10 15:32:13 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lstp;

	if (lst != NULL)
	{
		while (*lst != NULL)
		{
			lstp = *lst;
			*lst = (*lst)->next;
			del(lstp->content);
			free(lstp);
		}
		free(*lst);
	}
}
