/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:20:50 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/06 13:37:28 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putunbr_fd(unsigned long long n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
		count = ft_putunbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
	return (count + 1);
}

int	ft_putunbr_base_fd(unsigned long long nb, char *base, int fd)
{
	unsigned long long	len;
	int					count;

	count = 0;
	len = ft_strlen(base);
	if (nb >= len)
		count = ft_putunbr_base_fd(nb / len, base, fd) + 1;
	return (ft_putchar_fd(base[nb % len], fd) + count);
}
