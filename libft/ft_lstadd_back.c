/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:34:00 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/22 16:45:32 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*ptr;

	if (!alst || !*alst)
	{
		*alst = new;
		return ;
	}
	ptr = *alst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}
