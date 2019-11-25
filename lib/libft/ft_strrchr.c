/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:25:37 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/16 17:20:35 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	char	ch;

	str = NULL;
	ch = (char)c;
	while (1)
	{
		if (*s == ch)
			str = (char*)s;
		if (*s == '\0')
			return (str);
		s++;
	}
}
