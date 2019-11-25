/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:01:12 by jwisozk           #+#    #+#             */
/*   Updated: 2019/05/22 18:02:53 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*head;

	if (f == NULL)
		return (NULL);
	head = NULL;
	while (lst != NULL)
	{
		if (!(tmp = f(lst)))
		{
			ft_lstdel(&head, ft_del);
			return (NULL);
		}
		if (head == NULL)
			head = tmp;
		else
			ft_lstadd_back(&head, tmp);
		lst = lst->next;
	}
	return (head);
}
