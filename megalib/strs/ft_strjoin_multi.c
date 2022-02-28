/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_multi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 13:16:33 by ljourand          #+#    #+#             */
/*   Updated: 2022/01/26 13:10:28 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdarg.h>
#include <stdio.h>

static size_t	ft_get_length(size_t nb, va_list pi)
{
	size_t	i;
	size_t	length;
	char	*str;

	i = 0;
	length = 0;
	while (i < nb)
	{
		str = va_arg(pi, char *);
		length += ft_strlen(str);
		i++;
	}
	va_end(pi);
	return (length);
}

char	*ft_strjoin_multi(size_t nb, ...)
{
	size_t	length;
	size_t	i;
	char	*str;
	char	*output;

	va_list(pi);
	va_start(pi, nb);
	length = ft_get_length(nb, pi);
	output = ft_calloc(length + 1, 1);
	if (!output)
		return (0);
	va_start(pi, nb);
	i = 0;
	while (i < nb)
	{
		str = va_arg(pi, char *);
		ft_strlcat(output, str, length + 1);
		i++;
	}
	return (output);
}
