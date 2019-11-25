/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:04:37 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/30 17:04:37 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void				ft_update_sphere(t_data *data, t_lst *lst)
{
	t_sphere		*s;
	double			*d;
	int				*i;

	s = ft_create_sphere(data);
	while (lst != NULL)
	{
		i = (int*)lst->data;
		d = (double*)lst->data;
		if (ft_strequ(lst->type, CENTER) == 1)
			s->center = ft_create_vec3(d[0], d[1], d[2]);
		else if (ft_strequ(lst->type, TRANSLATION))
			s->translation = ft_create_vec3(d[0], d[1], d[2]);
		else if (ft_strequ(lst->type, COLOR) == 1)
			s->color = ft_rgb(i[0], i[1], i[2]);
		else if (ft_strequ(lst->type, RADIUS))
			s->radius = ft_atof((char*)lst->data);
		else if (ft_strequ(lst->type, SPECULAR))
			s->specular = ft_atoi((char*)lst->data);
		lst = lst->next;
	}
	if (s->center != NULL && s->translation != NULL)
		s->center = ft_translate(s->center, s->translation);
	data->sphere = s;
}

void				ft_update_cylinder(t_data *data, t_lst *lst)
{
	t_cylinder		*c;
	int				*i;

	c = ft_create_cylinder(data);
	while (lst != NULL)
	{
		i = (int*)lst->data;
		if (ft_strequ(lst->type, COLOR) == 1)
			c->color = ft_rgb(i[0], i[1], i[2]);
		else if (ft_strequ(lst->type, ROTATION))
			c->rotation = ft_create_ang3(i[0], i[1], i[2]);
		else if (ft_strequ(lst->type, SPECULAR) == 1)
			c->specular = ft_atoi((char*)lst->data);
		else if (ft_strequ(lst->type, RADIUS))
			c->radius = ft_atof((char*)lst->data);
		else
			ft_cylinder_min(&c, lst);
		lst = lst->next;
	}
	if (c->center != NULL && c->translation != NULL)
		c->center = ft_translate(c->center, c->translation);
	if (c->rotation != NULL)
		c->normal = ft_rotate(c->normal, c->rotation);
	data->cylinder = c;
}

void				ft_update_cone(t_data *data, t_lst *lst)
{
	t_cone			*c;
	int				*i;

	c = ft_create_cone(data);
	while (lst != NULL)
	{
		i = (int*)lst->data;
		if (ft_strequ(lst->type, COLOR) == 1)
			c->color = ft_rgb(i[0], i[1], i[2]);
		else if (ft_strequ(lst->type, ROTATION))
			c->rotation = ft_create_ang3(i[0], i[1], i[2]);
		else if (ft_strequ(lst->type, SPECULAR) == 1)
			c->specular = ft_atoi((char*)lst->data);
		else if (ft_strequ(lst->type, ANGLE))
			c->angle = TANH(ft_atoi((char*)lst->data));
		else
			ft_cone_min(&c, lst);
		lst = lst->next;
	}
	if (c->center != NULL && c->translation != NULL)
		c->center = ft_translate(c->center, c->translation);
	if (c->rotation != NULL)
		c->normal = ft_rotate(c->normal, c->rotation);
	data->cone = c;
}

void				ft_update_plane(t_data *data, t_lst *lst)
{
	t_plane			*p;
	int				*i;

	p = ft_create_plane(data);
	while (lst != NULL)
	{
		i = (int*)lst->data;
		if (ft_strequ(lst->type, COLOR) == 1)
			p->color = ft_rgb(i[0], i[1], i[2]);
		else if (ft_strequ(lst->type, ROTATION))
			p->rotation = ft_create_ang3(i[0], i[1], i[2]);
		else if (ft_strequ(lst->type, SPECULAR) == 1)
			p->specular = ft_atoi((char*)lst->data);
		else
			ft_plane_min(&p, lst);
		lst = lst->next;
	}
	if (p->point != NULL && p->translation != NULL)
		p->point = ft_translate(p->point, p->translation);
	if (p->rotation != NULL)
		p->normal = ft_rotate(p->normal, p->rotation);
	data->plane = p;
}
