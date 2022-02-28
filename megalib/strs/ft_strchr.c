/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 12:51:39 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/07 13:03:41 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*buffer;

	i = 0;
	buffer = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			buffer = (char *)&s[i];
		i++;
	}
	if (c == 0)
	{
		buffer = (char *)&s[i];
	}
	return (buffer);
}
