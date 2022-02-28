/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:45:58 by ljourand          #+#    #+#             */
/*   Updated: 2022/02/04 14:32:22 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int				i;
	size_t			length;
	unsigned int	start;

	if (!s1 || !set)
		return (0);
	if (set[0] == 0)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	i = ft_strlen(s1);
	while (i >= 0 && ft_strchr(set, s1[i]))
		i--;
	length = i - start + 1;
	return (ft_substr(s1, start, length));
}
