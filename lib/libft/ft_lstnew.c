/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 09:00:11 by jwisozk           #+#    #+#             */
/*   Updated: 2019/10/11 12:59:10 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*head;
	void	*data;

	if (!(head = (t_list*)ft_malloc(sizeof(*head))))
		return (NULL);
	if (!(data = ft_malloc(sizeof(*content) * content_size)))
	{
		ft_memdel((void**)&head);
		return (NULL);
	}
	if (content == NULL)
	{
		ft_memdel((void**)&data);
		head->content = NULL;
		head->content_size = 0;
	}
	else
	{
		data = ft_memcpy(data, content, content_size);
		head->content = data;
		head->content_size = content_size;
	}
	head->next = NULL;
	return (head);
}
