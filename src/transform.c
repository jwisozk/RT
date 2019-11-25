/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:08:14 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/28 19:08:14 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_vec3				*ft_translate(t_vec3 *o, t_vec3 *t)
{
	o->x += t->x;
	o->y += t->y;
	o->z += t->z;
	return (o);
}

void				ft_rot(double *a, double *b, int degree)
{
	double tmp_a;
	double tmp_b;

	tmp_a = *a;
	tmp_b = *b;
	*a = tmp_a * COS(degree) - tmp_b * SIN(degree);
	*b = tmp_a * SIN(degree) + tmp_b * COS(degree);
}

t_vec3				*ft_rotate(t_vec3 *v, t_ang3 *a)
{
	if (a->x)
		ft_rot(&v->y, &v->z, a->x);
	if (a->y)
		ft_rot(&v->x, &v->z, a->y);
	if (a->z)
		ft_rot(&v->x, &v->y, a->z);
	return (v);
}
