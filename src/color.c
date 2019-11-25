/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:37:26 by jwisozk           #+#    #+#             */
/*   Updated: 2019/08/28 14:33:50 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

int					ft_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

int					ft_multiply_color(double k, int color, int specular)
{
	int				r;
	int				g;
	int				b;
	int				p;

	p = 0;
	r = (color >> 16 & 255) * k;
	g = (color >> 8 & 255) * k;
	b = (color & 255) * k;
	if (specular > 0)
	{
		if (r > 255)
			p = r - 255;
		if (g > 255)
			p += g - 255;
		if (b > 255)
			p += b - 255;
	}
	r = ft_min(255, ft_max(0 + p, r));
	g = ft_min(255, ft_max(0 + p, g));
	b = ft_min(255, ft_max(0 + p, b));
	return (ft_rgb(r, g, b));
}
