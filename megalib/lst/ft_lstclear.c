/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljourand <ljourand@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:38:55 by ljourand          #+#    #+#             */
/*   Updated: 2021/12/11 20:03:43 by ljourand         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*lst_buff;

	while (*lst)
	{
		lst_buff = (*lst)->next;
		ft_lstdelone(*lst, (*del));
		*lst = lst_buff;
	}
}
