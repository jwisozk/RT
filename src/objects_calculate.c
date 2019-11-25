/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_calculate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:37:59 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/30 18:40:48 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

static double		ft_compare_t(double t1, double t2)
{
	if (t1 == t2)
		return (t1);
	else if (t1 > E && t2 > E)
		return (ft_min(t1, t2));
	else if (E < t1 && t1 < INF)
		return (t1);
	else if (E < t2 && t2 < INF)
		return (t2);
	else
		return (INF);
}

double				ft_calculate_sphere(t_ray *ray, t_sphere *s)
{
	t_vec3			*oc;
	double			discriminant;
	double			k[3];
	double			t1;
	double			t2;

	oc = ft_subtract(ray->origin, s->center);
	k[0] = ft_dot(ray->direct, ray->direct);
	k[1] = 2 * ft_dot(oc, ray->direct);
	k[2] = ft_dot(oc, oc) - s->radius * s->radius;
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant >= 0)
	{
		t1 = (-k[1] + sqrt(discriminant)) / (2 * k[0]);
		t2 = (-k[1] - sqrt(discriminant)) / (2 * k[0]);
		return (ft_compare_t(t1, t2));
	}
	return (INF);
}

double				ft_calculate_cylinder(t_ray *ray, t_cylinder *c)
{
	t_vec3			*oc;
	double			discriminant;
	double			k[3];
	double			t1;
	double			t2;

	oc = ft_subtract(ray->origin, c->center);
	k[0] = ft_dot(ray->direct, ray->direct) -
	pow(ft_dot(ray->direct, c->normal), 2);
	k[1] = 2 * (ft_dot(oc, ray->direct) - ft_dot(ray->direct, c->normal) *
	ft_dot(oc, c->normal));
	k[2] = ft_dot(oc, oc) - pow(ft_dot(oc, c->normal), 2) -
	c->radius * c->radius;
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant >= 0)
	{
		t1 = (-k[1] + sqrt(discriminant)) / (2 * k[0]);
		t2 = (-k[1] - sqrt(discriminant)) / (2 * k[0]);
		return (ft_compare_t(t1, t2));
	}
	return (INF);
}

double				ft_calculate_cone(t_ray *ray, t_cone *c)
{
	t_vec3			*oc;
	double			discriminant;
	double			k[3];
	double			t1;
	double			t2;

	oc = ft_subtract(ray->origin, c->center);
	k[0] = ft_dot(ray->direct, ray->direct) - (1 + pow(c->angle, 2)) *
	pow(ft_dot(ray->direct, c->normal), 2);
	k[1] = 2 * (ft_dot(oc, ray->direct) - (1 + pow(c->angle, 2)) *
	ft_dot(ray->direct, c->normal) * ft_dot(oc, c->normal));
	k[2] = ft_dot(oc, oc) - (1 + pow(c->angle, 2)) *
	pow(ft_dot(oc, c->normal), 2);
	discriminant = k[1] * k[1] - 4 * k[0] * k[2];
	if (discriminant >= 0)
	{
		t1 = (-k[1] + sqrt(discriminant)) / (2 * k[0]);
		t2 = (-k[1] - sqrt(discriminant)) / (2 * k[0]);
		return (ft_compare_t(t1, t2));
	}
	return (INF);
}
