/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:43:23 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/08 17:45:57 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!needle[0])
		return ((char *)haystack);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j] && haystack[i + j])
		{
			j++;
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
