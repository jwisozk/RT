/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:18:43 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/16 17:17:24 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	len_a;
	size_t	len_b;
	char	*str;

	str = (char*)haystack;
	if (*needle == '\0')
		return (str);
	i = len;
	len_a = ft_strlen(haystack);
	len_b = ft_strlen(needle);
	if (len_b > len)
		return (NULL);
	while (len_a-- > 0 && i-- > 0)
	{
		if (ft_strncmp(str++, needle, len_b) == 0)
			break ;
	}
	if (++i < len_b || *--str != *needle)
		return (NULL);
	return (str);
}
