/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:24:38 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/11 11:47:01 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_fd(long long n, int fd)
{
	int	count;
	int	digit;

	count = 0;
	if (n < 0)
	{
		n = -n;
		write(fd, "-", 1);
		count++;
	}
	if (n >= 10)
		count += ft_putnbr_fd(n / 10, fd);
	digit = n % 10 + '0';
	ft_putchar_fd(digit, fd);
	return (count + 1);
}

int	ft_putnbr_base_fd(long long nb, char *base, int fd)
{
	int	count;
	int	len;

	len = ft_strlen(base);
	if (len < 2)
		return (0);
	count = 0;
	if (nb < 0)
	{
		nb = -nb;
		write(fd, "-", 1);
		count++;
	}
	if (nb >= len)
		count += ft_putnbr_base_fd(nb / len, base, fd);
	return (count + ft_putchar_fd(base[nb % len], fd));
}
