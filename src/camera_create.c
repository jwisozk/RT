/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:06:35 by jwisozk           #+#    #+#             */
/*   Updated: 2019/10/13 14:25:28 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

t_cam				*ft_create_camera(void)
{
	t_cam *cam;

	if (!(cam = (t_cam*)ft_malloc(sizeof(t_cam))))
		ft_print(ft_msg(ERROR_29));
	cam->pos = NULL;
	cam->look_at = NULL;
	cam->forward = NULL;
	cam->left = NULL;
	cam->up = NULL;
	return (cam);
}
