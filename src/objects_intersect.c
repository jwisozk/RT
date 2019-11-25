/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_intersect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 22:38:24 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/29 15:41:25 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void				ft_sphere_intersect(t_ray *ray, t_obj *o)
{
	t_sphere		*s;
	double			t;

	s = (t_sphere*)o->objects;
	while (s != NULL)
	{
		t = ft_calculate_sphere(ray, s);
		if (t < o->t && ray->t_min < t && t < ray->t_max)
		{
			o->obj = s;
			o->t = t;
		}
		s = s->next;
	}
}

void				ft_cylinder_intersect(t_ray *ray, t_obj *o)
{
	t_cylinder		*c;
	double			t;

	c = (t_cylinder*)o->objects;
	while (c != NULL)
	{
		t = ft_calculate_cylinder(ray, c);
		if (t < o->t && ray->t_min < t && t < ray->t_max)
		{
			o->obj = c;
			o->t = t;
		}
		c = c->next;
	}
}

void				ft_cone_intersect(t_ray *ray, t_obj *o)
{
	t_cone			*c;
	double			t;

	c = (t_cone*)o->objects;
	while (c != NULL)
	{
		t = ft_calculate_cone(ray, c);
		if (t < o->t && ray->t_min < t && t < ray->t_max)
		{
			o->obj = c;
			o->t = t;
		}
		c = c->next;
	}
}

void				ft_plane_intersect(t_ray *ray, t_obj *o)
{
	t_plane			*p;
	double			angle;
	double			t;
	t_vec3			*op;

	p = (t_plane*)o->objects;
	while (p != NULL)
	{
		angle = ft_dot(p->normal, ray->direct);
		if (angle != 0)
		{
			op = ft_subtract(p->point, ray->origin);
			t = ft_dot(op, p->normal) / angle;
			if (t < o->t && ray->t_min < t && t < ray->t_max)
			{
				o->obj = p;
				o->t = t;
			}
		}
		p = p->next;
	}
}
