/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:37:56 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/06 11:18:32 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

char	*ft_strtolower(char *str)
{
	int		i;
	int		len;
	char	*output;

	i = 0;
	len = ft_strlen(str);
	output = ft_calloc(len + 1, sizeof (char));
	if (!output)
		return (0);
	while (i < len)
	{
		output[i] = ft_tolower(str[i]);
		i++;
	}
	return (output);
}
