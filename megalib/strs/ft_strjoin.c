/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:41:17 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/06 11:18:32 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*output;
	int		len1;
	int		len2;
	int		i;

	if (!s1 && !s2)
		return (0);
	if (!s1)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	if (!s2)
		return (ft_strdup(s1));
	len2 = ft_strlen(s2);
	output = ft_calloc(len1 + len2 + 1, sizeof (char));
	if (!output)
		return (0);
	i = -1;
	while (++i < len1)
		output[i] = s1[i];
	while (i < len1 + len2)
	{
		output[i] = s2[i - len1];
		i++;
	}
	return (output);
}
