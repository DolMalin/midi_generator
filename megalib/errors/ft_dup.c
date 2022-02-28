/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:02:19 by ljourand          #+#    #+#             */
/*   Updated: 2022/02/16 11:10:48 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_dup(int fd)
{
	int	dupped;

	dupped = dup(fd);
	if (dupped == -1)
	{
		perror("dup");
		exit(EXIT_FAILURE);
	}
	return (dupped);
}
