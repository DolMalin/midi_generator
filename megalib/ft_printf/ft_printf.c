/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:19:04 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/06 15:41:04 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_init_array(int (*f[8])(va_list, int))
{
	f[0] = ft_printc;
	f[1] = ft_prints;
	f[2] = ft_printp;
	f[3] = ft_printd;
	f[4] = ft_printd;
	f[5] = ft_printu;
	f[6] = ft_printx;
	f[7] = ft_printupperx;
}

static int	ft_iter(char *s, va_list pi, int (*f[8])(va_list, int), int fd)
{
	int		i;
	int		count;
	char	*charset;
	int		index;

	charset = "cspdiuxX";
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			index = ft_strchr(charset, s[i]) - charset;
			if (index < 0)
				count += ft_putchar_fd(s[i], fd);
			else
				count += f[index](pi, fd);
		}
		else if (s[i] != '%')
			count += ft_putchar_fd(s[i], fd);
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		(*functions[8])(va_list, int);

	va_list(pi);
	va_start(pi, format);
	ft_init_array(functions);
	count = ft_iter((char *)format, pi, functions, 1);
	va_end(pi);
	return (count);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int		count;
	int		(*functions[8])(va_list, int);

	va_list(pi);
	va_start(pi, format);
	ft_init_array(functions);
	count = ft_iter((char *)format, pi, functions, fd);
	va_end(pi);
	return (count);
}
