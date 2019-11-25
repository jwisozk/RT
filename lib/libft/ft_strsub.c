/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 23:00:32 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/16 17:19:31 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	l;

	if (s != NULL)
	{
		l = len;
		s += start;
		str = ft_strnew(len);
		if (!str)
			return (NULL);
		while (len--)
			*str++ = *s++;
		*str = '\0';
		return (str - l);
	}
	return (NULL);
}
