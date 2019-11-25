/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   etc_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iplastun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 22:17:44 by twill             #+#    #+#             */
/*   Updated: 2019/11/25 22:41:50 by iplastun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

//int					ft_close_window(t_data *data)
//{
////	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
//	exit(0);
//}

//int					ft_key_press(int key, t_data *data)
//{
//	if (key == 53)
//		ft_close_window(data);
//	return (0);
//}

t_lst				*ft_new_lst(char *type, void *data)
{
	t_lst			*lst;

	if (!(lst = (t_lst*)ft_malloc(sizeof(t_lst))))
		ft_print(ft_msg(ERROR_29));
	lst->type = type;
	lst->data = data;
	lst->next = NULL;
	return (lst);
}

void				ft_add_lst(t_lst **head, t_lst *new)
{
	if (head != NULL && new != NULL)
	{
		new->next = *head;
		*head = new;
	}
}

int					ft_check_substr(char *str, int num)
{
	if (num == 2)
	{
		if (ft_strequ(str, TYPE) || ft_strequ(str, INTENSITY)
		|| ft_strequ(str, ANGLE) || ft_strequ(str, RADIUS) ||
		ft_strequ(str, SPECULAR))
			return (1);
	}
	if (num == 4)
	{
		if (ft_strequ(str, POSITION) || ft_strequ(str, LOOK_AT)
		|| ft_strequ(str, CENTER) || ft_strequ(str, NORMAL) ||
		ft_strequ(str, TRANSLATION) || ft_strequ(str, POINT))
			return (1);
	}
	return (0);
}
