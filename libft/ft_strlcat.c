/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:07:34 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/08 17:22:01 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dest;
	size_t	len_src;

	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dest >= dstsize)
		return (dstsize + len_src);
	if (len_src < dstsize - len_dest)
		ft_strncat(dst, src, len_src + 1);
	else
	{
		ft_strncat(dst, src, dstsize - len_dest - 1);
		dst[dstsize - 1] = '\0';
	}
	return (len_dest + len_src);
}
