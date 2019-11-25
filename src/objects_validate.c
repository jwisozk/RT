/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:02:49 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/29 15:02:49 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void				ft_check_sphere(t_data *data)
{
	t_sphere		*s;

	s = data->sphere;
	while (s != NULL)
	{
		if (s->center == NULL)
			ft_print(ft_msg(ERROR_14));
		if (s->radius < 0)
			ft_print(ft_msg(ERROR_15));
		if (s->color < 0)
			ft_print(ft_msg(ERROR_16));
		s = s->next;
	}
}

void				ft_check_cylinder(t_data *data)
{
	t_cylinder		*c;

	c = data->cylinder;
	while (c != NULL)
	{
		if (c->center == NULL)
			ft_print(ft_msg(ERROR_17));
		if (c->normal == NULL || ft_lenv(c->normal) != 1)
			ft_print(ft_msg(ERROR_18));
		if (c->radius < 0)
			ft_print(ft_msg(ERROR_19));
		if (c->color < 0)
			ft_print(ft_msg(ERROR_20));
		c = c->next;
	}
}

void				ft_check_cone(t_data *data)
{
	t_cone			*c;

	c = data->cone;
	while (c != NULL)
	{
		if (c->center == NULL)
			ft_print(ft_msg(ERROR_21));
		if (c->normal == NULL || ft_lenv(c->normal) != 1)
			ft_print(ft_msg(ERROR_22));
		if (c->angle < 0)
			ft_print(ft_msg(ERROR_23));
		if (c->color < 0)
			ft_print(ft_msg(ERROR_24));
		c = c->next;
	}
}

void				ft_check_plane(t_data *data)
{
	t_plane			*p;

	p = data->plane;
	while (p != NULL)
	{
		if (p->point == NULL)
			ft_print(ft_msg(ERROR_25));
		if (p->normal == NULL || ft_lenv(p->normal) != 1)
			ft_print(ft_msg(ERROR_26));
		if (p->color < 0)
			ft_print(ft_msg(ERROR_27));
		p = p->next;
	}
}
