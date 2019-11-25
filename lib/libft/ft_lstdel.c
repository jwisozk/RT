/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:12:01 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/16 13:41:19 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*tmp;

	if (alst != NULL && del != NULL)
	{
		lst = *alst;
		while (lst != NULL)
		{
			tmp = lst;
			lst = lst->next;
			del(tmp->content, tmp->content_size);
			ft_memdel((void**)&tmp);
		}
		*alst = NULL;
	}
}
