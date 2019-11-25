/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 19:10:16 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/17 13:18:45 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	ch;

	ch = (unsigned char)c;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (n--)
	{
		if (*s == ch)
		{
			*d++ = *s++;
			return (d);
		}
		*d++ = *s++;
	}
	return (NULL);
}
