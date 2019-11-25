/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iplastun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:05:28 by jwisozk           #+#    #+#             */
/*   Updated: 2019/11/25 23:45:57 by iplastun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

char				*ft_msg(char *str)
{
	return (ft_strjoin(ERROR, str));
}

//void				ft_photo(char *str)
//{
//	t_data			data;
//	void			*mlx_ptr;
//	void			*win_ptr;
//	int				width;
//	int				height;
//
//	width = PHOTO_W;
//	height = PHOTO_H;
//	if ((mlx_ptr = mlx_init()) == NULL)
//		ft_print(ft_msg(ERROR_30));
//	if ((win_ptr = mlx_new_window(mlx_ptr, width, height, TEAM)) == NULL)
//		ft_print(ft_msg(ERROR_31));
//	if ((data.img.img_ptr =
//	mlx_xpm_file_to_image(mlx_ptr, str, &width, &height)) == NULL)
//		ft_print(ft_msg(ERROR_35));
//	mlx_put_image_to_window(mlx_ptr, win_ptr, data.img.img_ptr, 0, 0);
//	data.mlx_ptr = mlx_ptr;
//	data.win_ptr = win_ptr;
//	ft_clean();
//	mlx_hook(win_ptr, 17, 0, ft_close_window, &data);
//	mlx_hook(win_ptr, 2, 0, ft_key_press, &data);
//	mlx_loop(mlx_ptr);
//}

void				ft_check_argv(char *str)
{
	char			*ext1;
	char			*ext2;

//	if (ft_strequ(str, PHOTO))
//		ft_photo(str);
	ext1 = ft_strrev(str);
	ext2 = ft_strrev(EXTENSION);
	if (ft_strnequ(ext1, ext2, 4) != 1)
		ft_print(ft_msg(ERROR_1));
}

void				ft_open_file(char *name, int *fd)
{
	if ((*fd = open(name, O_RDONLY)) == -1)
		ft_print(ft_msg(ERROR_6));
}

void				ft_close_file(const int fd)
{
	if (close(fd) == -1)
		ft_print(ft_msg(ERROR_28));
}
