/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_waitpid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:04:39 by ljourand          #+#    #+#             */
/*   Updated: 2022/02/16 11:04:48 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_waitpid(pid_t pid, int *status, int options)
{
	if (waitpid(pid, status, options) == -1)
	{
		perror("waitpid");
		exit(EXIT_FAILURE);
	}
}
