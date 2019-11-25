/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:11:01 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/16 13:42:25 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*lst;

	if (alst != NULL && del != NULL)
	{
		lst = *alst;
		del(lst->content, lst->content_size);
		free(lst);
		*alst = NULL;
	}
}
