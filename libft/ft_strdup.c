/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:05:20 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/22 15:07:48 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	if (!(s2 = (char *)malloc((ft_strlen((char *)s1) + 1) * sizeof(char))))
		return (NULL);
	s2 = ft_strcpy(s2, s1);
	return (s2);
}
