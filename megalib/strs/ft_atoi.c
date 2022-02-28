/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:44:52 by ljourand          #+#    #+#             */
/*   Updated: 2022/01/24 14:36:12 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					signe;
	unsigned long long	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	signe = (str[i] == '-') * -1 + (str[i] != '-') * 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		if (signe == 1 && result > __LONG_LONG_MAX__)
			return (0);
		if (result > (unsigned long long)__LONG_LONG_MAX__ + 1)
			return (0);
		i++;
	}
	return ((int)(result * signe));
}
