/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:44:52 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/22 16:53:19 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*ptr;

	newlst = NULL;
	while (lst)
	{
		if (!(ptr = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&newlst, (*del));
			return (0);
		}
		ft_lstadd_back(&newlst, ptr);
		lst = lst->next;
	}
	return (newlst);
}
