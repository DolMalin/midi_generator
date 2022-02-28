/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 17:07:35 by ljourand          #+#    #+#             */
/*   Updated: 2022/02/16 11:09:46 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*output;
	int		i;

	if (!s)
		return (0);
	output = ft_malloc(ft_strlen(s) + 1);
	if (!output)
		return (0);
	output[ft_strlen(s)] = 0;
	i = 0;
	while (s[i])
	{
		output[i] = (*f)(i, s[i]);
		i++;
	}
	return (output);
}
