/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 13:05:02 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/06 11:18:32 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (!needle[0])
		return ((char *)haystack);
	if (len == 0)
		return (0);
	while (haystack[i] && i < len - ft_strlen(needle) + 1)
	{
		if (haystack[i] == needle[0])
		{
			n = 0;
			while (needle[n] && n < len)
			{
				if (needle[n] != haystack[n + i])
					break ;
				n++;
			}
			if (!needle[n])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
