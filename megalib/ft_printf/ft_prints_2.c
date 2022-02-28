/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:29:52 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/12 13:19:12 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printx(va_list pi, int fd)
{
	return (ft_putunbr_base_fd(va_arg(pi, int), "0123456789abcdef", fd), fd);
}

int	ft_printupperx(va_list pi, int fd)
{
	return (ft_putunbr_base_fd(va_arg(pi, int), "0123456789ABCDEF", fd), fd);
}
