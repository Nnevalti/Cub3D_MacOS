/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdescham <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 15:54:26 by vdescham          #+#    #+#             */
/*   Updated: 2019/10/22 16:37:58 by vdescham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			c;
	unsigned int	nb;

	if (n < 0)
	{
		write(fd, "-", 1);
		nb = -n;
	}
	else
		nb = n;
	if (nb < 10)
	{
		c = nb + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(nb / 10, fd);
		ft_putnbr_fd(nb % 10, fd);
	}
}
