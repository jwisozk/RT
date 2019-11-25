/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_update.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:05:13 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/30 17:05:13 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void				ft_update_light(t_data *data, t_lst *lst)
{
	t_light			*l;
	double			*d;

	l = ft_create_light(data);
	while (lst != NULL)
	{
		if (ft_strequ(lst->type, "type") == 1)
			l->type = (char*)lst->data;
		else if (ft_strequ(lst->type, "intensity") == 1)
			l->intensity = ft_atof((char*)lst->data);
		else if (ft_strequ(lst->type, "position") == 1)
		{
			d = (double*)lst->data;
			l->position = ft_create_vec3(d[0], d[1], d[2]);
		}
		lst = lst->next;
	}
	data->l = l;
}
