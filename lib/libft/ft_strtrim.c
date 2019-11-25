/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 06:10:32 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/16 17:23:47 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace_char(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	start;

	if (s != NULL)
	{
		len = ft_strlen(s);
		start = 0;
		while (ft_isspace_char(s[start]))
			start++;
		if (len - start == 0)
			return (ft_strsub(s, start, 0));
		while (ft_isspace_char(s[len - 1]))
			len--;
		len -= start;
		str = ft_strsub(s, start, len);
		if (!str)
			return (NULL);
		return (str);
	}
	return (NULL);
}
