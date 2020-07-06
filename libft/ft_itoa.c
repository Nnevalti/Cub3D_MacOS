/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:35:51 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/22 16:24:03 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countn(int n)
{
	long	mult;
	int		nb_chars;

	mult = 10;
	nb_chars = 0;
	while (n % mult != n)
	{
		mult *= 10;
		nb_chars++;
	}
	nb_chars++;
	return (n < 0 ? nb_chars + 1 : nb_chars);
}

static void	ft_putnbr_rec(char *str, unsigned int n)
{
	int		i;

	i = 0;
	if (n < 10)
	{
		while (str[i])
			i++;
		str[i] = n + '0';
	}
	else
	{
		ft_putnbr_rec(str, n / 10);
		ft_putnbr_rec(str, n % 10);
	}
}

char		*ft_itoa(int n)
{
	int				count;
	char			*str;
	unsigned int	nb;

	count = countn(n);
	str = (char *)ft_calloc(count + 1, sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		nb = -n;
		ft_putnbr_rec(str + 1, nb);
	}
	else
	{
		nb = n;
		ft_putnbr_rec(str, nb);
	}
	return (str);
}
