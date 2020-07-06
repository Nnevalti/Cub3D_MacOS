/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <vdescham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:27:16 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/23 15:53:08 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_mallocstr(char const *s, char c)
{
	int		i;
	char	*str;
	int		nb_chars;

	nb_chars = 0;
	while (s[nb_chars] && s[nb_chars] != c)
		nb_chars++;
	if (!(str = (char *)malloc((nb_chars + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < nb_chars)
	{
		str[i] = s[i];
		i++;
	}
	str[nb_chars] = '\0';
	return (str);
}

static int		ft_countset(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

char			**ft_split(char const *s, char c)
{
	int		i;
	int		nb_strings;
	char	**tab;

	if (!s)
		return (0);
	nb_strings = ft_countset(s, c);
	if (!(tab = (char **)malloc((nb_strings + 1) * sizeof(char *))))
		return (NULL);
	i = 0;
	while (i < nb_strings)
	{
		while (*s == c)
			s++;
		if (*s != '\0')
			tab[i] = ft_mallocstr(s, c);
		while (*s && *s != c)
			s++;
		i++;
	}
	tab[nb_strings] = NULL;
	return (tab);
}
