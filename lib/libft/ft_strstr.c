/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:52:21 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/05 15:26:30 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		len_a;
	int		len_b;
	char	*str;

	str = (char*)haystack;
	if (*needle == '\0')
		return (str);
	len_a = ft_strlen(haystack);
	len_b = ft_strlen(needle);
	while (len_a-- > 0)
	{
		if (ft_strncmp(str, needle, len_b) == 0)
			break ;
		str++;
	}
	if (*str == '\0' && *needle != '\0')
		return (NULL);
	return (str);
}
