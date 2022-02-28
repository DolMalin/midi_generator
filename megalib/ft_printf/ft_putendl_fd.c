/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:22:40 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/06 13:36:48 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	count;

	count = ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
	return (count + 1);
}
