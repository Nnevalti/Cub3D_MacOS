/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:50:42 by vdescham          #+#    #+#             */
/*   Updated: 2020/03/02 17:50:43 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cub3D.h"

int		ft_isspace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int		is_charset(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		is_map(char *line)
{
	int		i;

	i = 0;
	if (line[0] == '\0')
		return (0);
	while (line[i])
	{
		if (is_charset(line[i], "NSEW012 "))
			i++;
		else
			return (0);
	}
	return (1);
}

int		ft_strlen_nospace(char *s1)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s1[i])
	{
		if (ft_isalnum(s1[i]))
			len++;
		i++;
	}
	return (len);
}

char	*ft_strdup_nospace(char *s1)
{
	char	*s2;
	int		len;
	int		i;
	int		j;

	len = ft_strlen_nospace(s1);
	i = 0;
	if (!(s2 = (char *)malloc(len + 1 * sizeof(char))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		if (!(ft_isspace(s1[i])))
		{
			s2[j] = s1[i];
			j++;
		}
		i++;
	}
	s2[j] = '\0';
	return (s2);
}
