/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:51:35 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/28 19:01:06 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

static double		ft_map_x(int x, double size, int width)
{
	return (x * size / width - (size / 2));
}

static double		ft_map_y(int y, double size, int height)
{
	return (-y * size / height + (size / 2));
}

void				ft_camera_ray(t_data *data, int x, int y)
{
	t_vec3 *new_forw;
	t_vec3 *new_left;
	t_vec3 *new_up;
	t_vec3 *left_up;

	new_left = ft_multiply(ft_map_x(x, VW, DW), data->cam->left);
	new_up = ft_multiply(ft_map_y(y, VH, DH), data->cam->up);
	new_forw = ft_multiply(D, data->cam->forward);
	left_up = ft_add(new_up, new_left);
	data->ray = ft_create_ray(NULL, NULL, 1, INF);
	data->ray->direct = ft_normalize_vec3(ft_add(left_up, new_forw));
	data->ray->origin = data->cam->pos;
}

void				ft_camera_look_at(t_data *data)
{
	t_vec3 *forward;
	t_vec3 *left;
	t_vec3 *up;
	t_vec3 *tmp;

	forward = ft_normalize_vec3(ft_subtract(data->cam->look_at,
	data->cam->pos));
	if (forward->x == 0 && forward->z == 0 &&
	(forward->y == 1 || forward->y == -1))
		tmp = ft_create_vec3(0, 0, -1);
	else
		tmp = ft_create_vec3(0, 1, 0);
	left = ft_normalize_vec3(ft_cross_product(tmp, forward));
	up = ft_normalize_vec3(ft_cross_product(forward, left));
	data->cam->forward = forward;
	data->cam->up = up;
	data->cam->left = left;
}
