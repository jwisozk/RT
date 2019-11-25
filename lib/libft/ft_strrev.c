/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 19:48:28 by jwisozk           #+#    #+#             */
/*   Updated: 2018/12/16 19:54:59 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	len;
	char	*new;

	if (str != NULL)
	{
		len = ft_strlen(str);
		new = ft_strnew(len);
		if (!new)
			return (NULL);
		while (len--)
			new[len] = *str++;
		return (new);
	}
	return (NULL);
}
