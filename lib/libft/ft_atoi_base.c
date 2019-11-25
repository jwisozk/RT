/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/30 22:12:27 by twill             #+#    #+#             */
/*   Updated: 2019/06/30 22:12:31 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isvalid(char c, int base)
{
	int n;

	if (c >= 48 && c <= 57)
		n = c - 48;
	else if (c >= 65 && c <= 70)
		n = c - 55;
	else if (c >= 97 && c <= 102)
		n = c - 87;
	else
		n = -1;
	if (n > --base)
		n = -1;
	return (n);
}

static int	ft_base_definer(char **str)
{
	char	*ptr;

	ptr = *str;
	if (*ptr > 48 && *ptr <= 57)
		return (10);
	if (*ptr == 48)
	{
		if (*(ptr + 1) == 'x' || *(ptr + 1) == 'X')
		{
			*str = *str + 2;
			return (16);
		}
		*str = *str + 1;
		return (8);
	}
	return (0);
}

int			ft_atoi_base(char **str)
{
	int		base;
	long	value;
	int		status;
	int		num;
	char	*ptr;

	if (!(base = ft_base_definer(str)))
		return (0);
	status = 1;
	value = 0;
	ptr = *str;
	while (ft_isspace(*ptr))
		ptr++;
	if (*ptr == '-')
		status = -1;
	if (*ptr == '-' || *ptr == '+')
		ptr++;
	while ((num = ft_isvalid(*ptr, base)) != -1)
	{
		value = value * base + num;
		if (num < 10 && value % base != num)
			return (status == -1 ? 0 : -1);
		ptr++;
	}
	return (value * status);
}
