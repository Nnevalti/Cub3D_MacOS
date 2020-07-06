/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:28:49 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/22 11:39:10 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	i = 0;
	d = dst;
	s = src;
	while (i < n)
	{
		d[i] = (unsigned char)s[i];
		if ((unsigned char)d[i] == (unsigned char)c)
			return (&(d[i + 1]));
		i++;
	}
	return (0);
}
