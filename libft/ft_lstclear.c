/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:04:06 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/22 16:47:51 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*next;

	ptr = *lst;
	while (ptr)
	{
		(*del)(ptr->content);
		next = ptr->next;
		free(ptr);
		ptr = next;
	}
	*lst = NULL;
}
