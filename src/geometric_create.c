/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometric_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:05:40 by jwisozk           #+#    #+#             */
/*   Updated: 2019/10/13 14:25:28 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_vec3				*ft_create_vec3(double x, double y, double z)
{
	t_vec3 *p;

	if (!(p = (t_vec3*)ft_malloc(sizeof(t_vec3))))
		ft_print(ft_msg(ERROR_29));
	p->x = x;
	p->y = y;
	p->z = z;
	return (p);
}

t_ang3				*ft_create_ang3(int x, int y, int z)
{
	t_ang3 *a;

	if (!(a = (t_ang3*)ft_malloc(sizeof(t_ang3))))
		ft_print(ft_msg(ERROR_29));
	a->x = x;
	a->y = y;
	a->z = z;
	return (a);
}

t_ray				*ft_create_ray(t_vec3 *origin, t_vec3 *direct,
					double t_min, double t_max)
{
	t_ray *i;

	if (!(i = (t_ray*)ft_malloc(sizeof(t_ray))))
		ft_print(ft_msg(ERROR_29));
	i->origin = origin;
	i->direct = direct;
	i->t_min = t_min;
	i->t_max = t_max;
	return (i);
}

t_point				*ft_create_point(void)
{
	t_point *p;

	if (!(p = (t_point*)ft_malloc(sizeof(t_point))))
		ft_print(ft_msg(ERROR_29));
	p->point = NULL;
	p->normal = NULL;
	p->color = ft_rgb(BACKGROUND);
	p->specular = -1;
	p->type = -1;
	p->po = NULL;
	p->center = NULL;
	p->cam = NULL;
	return (p);
}
