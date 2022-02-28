/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:57:31 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/06 13:29:54 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_get_nb_digits(long long n)
{
	int		count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(long long n)
{
	char	*output;
	int		length;

	length = ft_get_nb_digits(n);
	output = ft_calloc(length + 1, sizeof (char));
	if (!output)
		return (0);
	if (n == 0)
		output[0] = '0';
	if (n < 0)
	{
		n = -n;
		output[0] = '-';
	}
	while (n > 0)
	{
		length--;
		output[length] = n % 10 + '0';
		n = n / 10;
	}
	return (output);
}
