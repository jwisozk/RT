/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:26:25 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/29 15:26:25 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void				ft_update_camera(t_data *data, t_lst *lst)
{
	t_cam			*cam;
	double			*d;

	cam = ft_create_camera();
	while (lst != NULL)
	{
		d = (double*)lst->data;
		if (ft_strequ(lst->type, "position") == 1)
			cam->pos = ft_create_vec3(d[0], d[1], d[2]);
		else if (ft_strequ(lst->type, "look_at") == 1)
			cam->look_at = ft_create_vec3(d[0], d[1], d[2]);
		lst = lst->next;
	}
	data->cam = cam;
}
