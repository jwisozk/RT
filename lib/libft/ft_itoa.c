/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 19:23:00 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/29 20:57:23 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_get_len(long num)
{
	int len;

	len = 1;
	if (num < 0)
		len = 2;
	while ((num /= 10) != 0)
		len++;
	return (len);
}

static	void	ft_convert(char *str, long num)
{
	if (num >= 10)
		ft_convert(str - 1, num / 10);
	if (*str != '-')
		*str = num % 10 + '0';
}

static	void	ft_fill_str(char *str, int len)
{
	int i;

	i = 0;
	while (i <= len)
	{
		str[i] = 0;
		i++;
	}
}

char			*ft_itoa(int n)
{
	int		len;
	long	num;
	char	*str;

	num = n;
	len = ft_get_len(n);
	if (!(str = (char*)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_fill_str(str, len);
	if (num < 0)
	{
		*str = '-';
		num *= -1;
	}
	ft_convert(str + len - 1, num);
	return (str);
}
