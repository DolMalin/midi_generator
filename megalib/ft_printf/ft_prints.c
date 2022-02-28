/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:17:18 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/06 11:35:27 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printc(va_list pi, int fd)
{
	char	c;

	c = va_arg(pi, int);
	return (ft_putchar_fd(c, fd));
}

int	ft_prints(va_list pi, int fd)
{
	char	*str;

	str = va_arg(pi, char *);
	if (str)
		return (ft_putstr_fd(str, fd));
	return (ft_putstr_fd("(null)", fd));
}

int	ft_printp(va_list pi, int fd)
{
	ft_putchar_fd('0', fd);
	ft_putchar_fd('x', fd);
	return (ft_putunbr_base_fd(va_arg(pi, int), "0123456789abcdef", fd) + 2);
}

int	ft_printd(va_list pi, int fd)
{
	return (ft_putnbr_fd(va_arg(pi, int), fd));
}

int	ft_printu(va_list pi, int fd)
{
	return (ft_putunbr_fd(va_arg(pi, int), fd));
}
