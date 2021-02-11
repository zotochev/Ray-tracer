/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscot <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:17:31 by mscot             #+#    #+#             */
/*   Updated: 2020/11/05 18:17:36 by mscot            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstp;

	if (lst != NULL)
	{
		lstp = *lst;
		if (*lst == NULL)
			*lst = new;
		else
		{
			while (lstp->next != NULL)
				lstp = lstp->next;
			lstp->next = new;
		}
	}
}
