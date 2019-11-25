/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:00:11 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/29 20:57:23 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_get_count_words(char const *s, char c)
{
	int	count;

	if (s == NULL)
		return (0);
	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
			continue ;
		}
		s++;
	}
	return (count);
}

static	int		ft_get_len_word(char const *s, char c)
{
	int len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ptr;
	int		count;
	int		len;
	int		i;

	count = ft_get_count_words(s, c);
	if (!(ptr = (char**)ft_malloc(sizeof(*ptr) * (count + 1))))
		return (NULL);
	ptr[count] = NULL;
	i = 0;
	while (s != NULL && i < count && *s != '\0')
	{
		len = 1;
		if (*s != c)
		{
			len = ft_get_len_word(s, c);
			if (!(ptr[i] = (char*)ft_malloc(sizeof(char) * (len + 1))))
				return ((char**)ft_free_all((void**)ptr, i));
			ptr[i] = ft_strncpy(ptr[i], s, len);
			ptr[i][len] = '\0';
			i++;
		}
		s += len;
	}
	return (ptr);
}
