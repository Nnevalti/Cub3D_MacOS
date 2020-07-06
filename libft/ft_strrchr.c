/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:54:57 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/22 12:01:36 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;

	len = ft_strlen((char *)s) - 1;
	if (c == '\0')
		len++;
	while (len >= 0 && (s[len] || c == '\0'))
	{
		if (s[len] == c)
			return ((char *)&(s[len]));
		len--;
	}
	return (0);
}
