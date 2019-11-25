/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 19:01:12 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/29 15:34:39 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void				ft_check_camera(t_data *data)
{
	t_vec3			*a;
	t_vec3			*b;

	if (data->cam == NULL)
		ft_print(ft_msg(ERROR_7));
	a = data->cam->look_at;
	b = data->cam->pos;
	if (a == NULL)
		ft_print(ft_msg(ERROR_8));
	if (b == NULL)
		ft_print(ft_msg(ERROR_9));
	if (a->x == b->x &&
		a->y == b->y &&
		a->z == b->z)
		ft_print(ft_msg(ERROR_10));
}
