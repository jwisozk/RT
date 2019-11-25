/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 19:09:43 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/16 16:11:15 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char const *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	dfree;

	dlen = 0;
	while (dlen < size && dst[dlen] != '\0')
		dlen++;
	dfree = size - dlen;
	if (dfree == 0)
		return (dlen + ft_strlen(src));
	i = 0;
	j = dlen;
	while (i < (dfree - 1) && src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dlen + ft_strlen(src));
}
