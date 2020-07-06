/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:35:28 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/25 17:37:02 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*mem;
	unsigned int	size;
	unsigned int	i;

	if (!s || start >= ft_strlen(s))
		return ((char *)ft_calloc(1, sizeof(char)));
	size = (start + len > ft_strlen(s)) ? ft_strlen(s) - start : len;
	if (!(mem = (char *)malloc((size + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (i < size)
	{
		mem[i] = s[start + i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
