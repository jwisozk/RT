/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iplastun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:19:43 by jwisozk           #+#    #+#             */
/*   Updated: 2019/11/25 23:15:16 by iplastun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void				ft_init_shapes(t_data *data)
{
	data->sphere = NULL;
	data->plane = NULL;
	data->cylinder = NULL;
	data->cone = NULL;
	data->p = ft_create_point();
	data->o = NULL;
	data->l = NULL;
	data->cam = NULL;
	data->pass = NULL;
	data->sdl.pixels = (int*)malloc(sizeof(int) * SCREEN_SIZE);
}

void				ft_check_valid(t_data *data)
{
	ft_check_camera(data);
	ft_check_light(data);
	ft_check_sphere(data);
	ft_check_cylinder(data);
	ft_check_cone(data);
	ft_check_plane(data);
}

int					main(int argc, char **argv)
{
	int				fd;
	t_data			data;

	if (argc == 2)
	{
		ft_check_argv(argv[1]);
		ft_open_file(argv[1], &fd);
		ft_init_shapes(&data);
		ft_get_scene(fd, &data);
		ft_close_file(fd);
		ft_check_valid(&data);
		ft_draw(&data);
		ft_clean();
		ft_sdl2_main(&data.sdl);
	}
	else
		ft_print(USAGE);
	return (0);
}
