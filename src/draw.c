/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iplastun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 20:23:15 by jwisozk           #+#    #+#             */
/*   Updated: 2019/11/25 22:33:21 by iplastun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_obj				*ft_find_closest_obj(t_obj *obj, t_ray *ray)
{
	static t_arr_obj	arr[] = ARR_OBJ;
	int					i;
	int					max;

	i = 0;
	max = sizeof(arr) / sizeof(t_arr_obj);
	while (i < max)
	{
		if (arr[i].type == obj->type)
		{
			obj->t = INF;
			arr[i].ft_obj_intersect(ray, obj);
			return (obj);
		}
		i++;
	}
	return (NULL);
}

void				ft_obj_fill(t_obj *obj, t_point *p, t_ray *ray)
{
	static t_arr_obj	arr[] = ARR_OBJ;
	int					i;
	int					max;

	i = 0;
	max = sizeof(arr) / sizeof(t_arr_obj);
	while (i < max)
	{
		if (arr[i].type == obj->type)
		{
			p->type = obj->type;
			p->po = ft_multiply(-1, ray->direct);
			p->cam = ray->origin;
			arr[i].ft_obj_fill(obj, p, ray);
		}
		i++;
	}
}

t_obj				*ft_scene_intersect(t_obj *o, t_ray *ray)
{
	t_obj			*obj;
	t_obj			*tmp_obj;
	double			t;

	obj = NULL;
	t = INF;
	while (o != NULL)
	{
		tmp_obj = ft_find_closest_obj(o, ray);
		if (tmp_obj != NULL && tmp_obj->t < t)
		{
			t = tmp_obj->t;
			obj = tmp_obj;
		}
		o = o->next;
	}
	return (obj);
}

int					ft_trace_ray(t_data *data)
{
	t_obj			*obj;
	double			lighting;

	if ((obj = ft_scene_intersect(data->o, data->ray)) == NULL)
		return (ft_rgb(BACKGROUND));
	ft_obj_fill(obj, data->p, data->ray);
	lighting = ft_lighting(data->p, data->l, data->o);
	return (ft_multiply_color(lighting, data->p->color, data->p->specular));
}

void				ft_draw(t_data *data)
{
	int				i;
	int				j;

	i = 0;
	ft_camera_look_at(data);
	while (i < DH)
	{
		j = 0;
		while (j < DW)
		{
			ft_camera_ray(data, j, i);
			data->p->color = ft_trace_ray(data);
			data->sdl.pixels[i * DW + j] = data->p->color;
			j++;
		}
		i++;
	}
}
