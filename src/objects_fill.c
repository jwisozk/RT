/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_fill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:23:15 by jwisozk           #+#    #+#             */
/*   Updated: 2019/10/13 11:41:04 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void				ft_sphere_fill(t_obj *obj, t_point *p, t_ray *ray)
{
	t_sphere		*s;
	t_vec3			*radius;

	s = (t_sphere*)obj->obj;
	p->type = obj->type;
	p->point = ft_add(ray->origin, ft_multiply(obj->t, ray->direct));
	radius = ft_subtract(p->point, s->center);
	p->color = s->color;
	p->specular = s->specular;
	p->normal = ft_normalize_vec3(radius);
	p->normal = (ft_dot(p->normal, p->po) < 0) ? ft_multiply(-1, p->normal) :
				p->normal;
}

void				ft_cylinder_fill(t_obj *obj, t_point *p, t_ray *ray)
{
	t_cylinder		*c;
	t_vec3			*oc;
	t_vec3			*pc;
	t_vec3			*radius;
	double			m;

	c = (t_cylinder*)obj->obj;
	p->point = ft_add(ray->origin, ft_multiply(obj->t, ray->direct));
	oc = ft_subtract(ray->origin, c->center);
	m = ft_dot(ray->direct, ft_multiply(obj->t, c->normal)) +
		ft_dot(oc, c->normal);
	pc = ft_subtract(p->point, c->center);
	radius = ft_subtract(pc, ft_multiply(m, c->normal));
	p->color = c->color;
	p->specular = c->specular;
	p->normal = ft_normalize_vec3(radius);
	p->normal = (ft_dot(p->normal, p->po) <= 0) ? ft_multiply(-1, p->normal) :
				p->normal;
}

void				ft_cone_fill(t_obj *obj, t_point *p, t_ray *ray)
{
	t_cone *c;
	t_vec3 *oc;
	t_vec3 *pc;
	t_vec3 *radius;
	double m;

	c = (t_cone *)obj->obj;
	p->point = ft_add(ray->origin, ft_multiply(obj->t, ray->direct));
	oc = ft_subtract(ray->origin, c->center);
	m = ft_dot(ray->direct, ft_multiply(obj->t, c->normal)) +
		ft_dot(oc, c->normal);
	pc = ft_subtract(p->point, c->center);
	radius = ft_subtract(pc, ft_multiply(m * (1 + pow(c->angle, 2)),
	c->normal));
	c->normal = (ft_dot(c->normal, p->po) < 0) ? ft_multiply(-1, c->normal) :
				c->normal;
	p->color = c->color;
	p->specular = c->specular;
	p->center = c->center;
	p->normal = ft_normalize_vec3(radius);
	p->normal = (ft_dot(p->normal, p->po) < 0) ? ft_multiply(-1, p->normal) :
				p->normal;
}

void				ft_plane_fill(t_obj *obj, t_point *p, t_ray *ray)
{
	t_plane			*pl;
	t_vec3			*po;
	double			angle_on;

	pl = (t_plane*)obj->obj;
	p->point = ft_add(ray->origin, ft_multiply(obj->t, ray->direct));
	po = ft_subtract(ray->origin, p->point);
	angle_on = ft_dot(pl->normal, po);
	p->color = pl->color;
	p->specular = pl->specular;
	p->normal = (angle_on < 0) ? ft_multiply(-1, pl->normal) : pl->normal;
}
