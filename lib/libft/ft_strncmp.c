/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 20:04:25 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/16 19:02:56 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(char const *s1, char const *s2, size_t n)
{
	unsigned char *str1;
	unsigned char *str2;

	if (n == 0)
		return (0);
	str1 = (unsigned char*)s1;
	str2 = (unsigned char*)s2;
	while (*str1 != '\0' || *str2 != '\0')
	{
		if (*str1 - *str2 != 0 || n == 1)
			return (*str1 - *str2);
		str1++;
		str2++;
		n--;
	}
	return (0);
}
