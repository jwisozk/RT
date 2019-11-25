/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:22:17 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/30 17:22:17 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double		ft_loop(const char *str, double sign)
{
	double	value;
	int		point;

	point = 0;
	value = 0;
	while (ft_isdigit(*str) || *str == '.')
	{
		if (*str == '.')
		{
			if (point == 1)
				break ;
			point = 1;
			str++;
			continue ;
		}
		if (point == 1)
			sign /= 10.0f;
		value = 10 * value + *str - '0';
		str++;
	}
	return (value * sign);
}

double				ft_atof(const char *str)
{
	double	sign;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	return (ft_loop(str, sign));
}
