/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 14:35:34 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/29 14:35:34 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

double				ft_lenv(t_vec3 *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

double				ft_dot(t_vec3 *v1, t_vec3 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

double				ft_max(double x, double y)
{
	return (x > y ? x : y);
}

double				ft_min(double x, double y)
{
	return (x < y ? x : y);
}

int					ft_compare_vec3(t_vec3 *a, t_vec3 *b)
{
	if (a->x == b->x && a->y == b->y && a->z == b->z)
		return (1);
	return (0);
}
