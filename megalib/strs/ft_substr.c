/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:34:48 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/06 13:30:42 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*output;
	size_t			i;
	unsigned int	length;

	if (!s || len < 0)
		return (0);
	length = ft_strlen(s);
	if (start > length)
		return (0);
	if (length - start < len)
		len = length - start;
	output = ft_calloc(len + 1, sizeof (char));
	if (!output)
		return (0);
	i = 0;
	while (i < len && start + i < length)
	{
		output[i] = s[start + i];
		i++;
	}
	return (output);
}
