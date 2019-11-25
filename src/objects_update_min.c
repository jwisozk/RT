/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_update_min.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:07:08 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/30 17:07:08 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void				ft_cylinder_min(t_cylinder **c, t_lst *lst)
{
	double			*d;

	d = (double*)lst->data;
	if (ft_strequ(lst->type, CENTER) == 1)
		(*c)->center = ft_create_vec3(d[0], d[1], d[2]);
	else if (ft_strequ(lst->type, TRANSLATION))
		(*c)->translation = ft_create_vec3(d[0], d[1], d[2]);
	else if (ft_strequ(lst->type, NORMAL))
		(*c)->normal = ft_create_vec3(d[0], d[1], d[2]);
}

void				ft_cone_min(t_cone **c, t_lst *lst)
{
	double			*d;

	d = (double*)lst->data;
	if (ft_strequ(lst->type, CENTER) == 1)
		(*c)->center = ft_create_vec3(d[0], d[1], d[2]);
	else if (ft_strequ(lst->type, TRANSLATION))
		(*c)->translation = ft_create_vec3(d[0], d[1], d[2]);
	else if (ft_strequ(lst->type, NORMAL))
		(*c)->normal = ft_create_vec3(d[0], d[1], d[2]);
}

void				ft_plane_min(t_plane **p, t_lst *lst)
{
	double			*d;

	d = (double*)lst->data;
	if (ft_strequ(lst->type, POINT) == 1)
		(*p)->point = ft_create_vec3(d[0], d[1], d[2]);
	else if (ft_strequ(lst->type, TRANSLATION))
		(*p)->translation = ft_create_vec3(d[0], d[1], d[2]);
	else if (ft_strequ(lst->type, NORMAL))
		(*p)->normal = ft_create_vec3(d[0], d[1], d[2]);
}
