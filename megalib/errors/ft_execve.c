/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:05:35 by ljourand          #+#    #+#             */
/*   Updated: 2022/02/16 11:05:44 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_execve(char *path, char **args, char **env)
{
	if (execve(path, args, env) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}
