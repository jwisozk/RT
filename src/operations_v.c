/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_v.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:33:15 by jwisozk           #+#    #+#             */
/*   Updated: 2019/08/28 14:38:29 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_vec3				*ft_cross_product(t_vec3 *a, t_vec3 *b)
{
	t_vec3			*c;

	c = ft_create_vec3(0, 0, 0);
	c->x = a->y * b->z - a->z * b->y;
	c->y = a->z * b->x - a->x * b->z;
	c->z = a->x * b->y - a->y * b->x;
	return (c);
}

t_vec3				*ft_multiply(double k, t_vec3 *v)
{
	t_vec3			*p;

	p = ft_create_vec3(v->x * k, v->y * k, v->z * k);
	return (p);
}

t_vec3				*ft_add(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3			*p;

	p = ft_create_vec3(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
	return (p);
}

t_vec3				*ft_subtract(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3			*p;

	p = ft_create_vec3(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
	return (p);
}

t_vec3				*ft_normalize_vec3(t_vec3 *v)
{
	double			len;
	double			inv_len;
	t_vec3			*nv;

	nv = ft_create_vec3(v->x, v->y, v->z);
	len = ft_lenv(v);
	if (len > 0)
	{
		inv_len = 1.0 / len;
		nv->x *= inv_len;
		nv->y *= inv_len;
		nv->z *= inv_len;
	}
	return (nv);
}
