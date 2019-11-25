/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:43:23 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/29 20:57:23 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*s;

	if (size + 1 == 0)
		return (NULL);
	s = (unsigned char*)malloc(sizeof(*s) * size);
	if (!s)
		return (NULL);
	ft_bzero(s, size);
	return (s);
}
