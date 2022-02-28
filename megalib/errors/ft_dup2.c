/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:02:48 by ljourand          #+#    #+#             */
/*   Updated: 2022/02/16 11:02:57 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_dup2(int fd1, int fd2)
{
	if (dup2(fd1, fd2) == -1)
	{
		perror("dup2");
		exit(EXIT_FAILURE);
	}
	ft_close(fd1);
}
