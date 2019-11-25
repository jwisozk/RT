/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_validate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 15:34:45 by jwisozk           #+#    #+#             */
/*   Updated: 2019/09/29 15:34:45 by jwisozk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void				ft_check_light(t_data *data)
{
	t_light			*l;
	static char		*arr[3] = LIGHT_TYPES;
	int				i;
	int				c;

	l = data->l;
	while (l != NULL)
	{
		i = 0;
		c = 0;
		while (i < 3)
		{
			if (ft_strequ(l->type, arr[i]) != 1)
				c++;
			i++;
		}
		if (c == 3)
			ft_print(ft_msg(ERROR_11));
		if (l->position == NULL)
			ft_print(ft_msg(ERROR_12));
		if (l->intensity < 0)
			ft_print(ft_msg(ERROR_13));
		l = l->next;
	}
}
