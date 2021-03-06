/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jargote <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 22:33:30 by jargote           #+#    #+#             */
/*   Updated: 2016/11/11 15:46:06 by jargote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		num;
	char	digit;

	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		n += 2000000000;
		n *= -1;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > -2147483648 && n <= 2147483647)
	{
		num = n % 10;
		n = n / 10;
		digit = num + 48;
		if (n != 0)
			ft_putnbr_fd(n, fd);
		write(fd, &digit, 1);
	}
}
