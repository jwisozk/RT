/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 22:17:26 by twill             #+#    #+#             */
/*   Updated: 2019/10/13 22:17:30 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void				ft_check_braces(int *block, int n)
{
	int				err;

	err = 0;
	if (*block > 0 && n == 1)
		err = 1;
	if (*block == 0 && n == 2)
		err = 1;
	if (*block != 0 && n == 3)
		err = 1;
	if (n == 1)
		(*block)++;
	if (n == 2)
		(*block)--;
	if (err == 1)
		ft_print(ft_msg(ERROR_3));
}

int					ft_is_hash(char *line, int *i)
{
	static t_arr_type		arr[] = ARR_TYPES;
	char					**type;
	int						max;

	if (*line != '#')
		return (0);
	max = sizeof(arr) / sizeof(t_arr_type);
	if ((type = ft_strsplit(line + 1, ' ')) == NULL)
		ft_print(ft_msg(ERROR_29));
	*i = 0;
	while (*i < max && ft_strequ(type[0], arr[*i].type) != 1)
		(*i)++;
	if (*i == max)
		ft_print(ft_msg(ERROR_2));
	return (1);
}

void				ft_get_data(t_lst **lst, char *line)
{
	int		j;
	char	**str;
	t_lst	*tmp;

	if ((str = ft_strsplit(line, ' ')) == NULL)
		ft_print(ft_msg(ERROR_29));
	if (str[0] == NULL)
		return ;
	j = 0;
	while (str[j] != NULL)
		j++;
	if (j == 1 || j == 3)
		return ;
	if (j == 2 && ft_check_substr(str[0], j) == 1)
		tmp = ft_new_lst(str[0], str[1]);
	else if (j == 4 && ft_check_substr(str[0], j) == 1)
		tmp = ft_new_lst(str[0], ft_new_arr_d(str[1], str[2], str[3]));
	else if (j == 4 && (ft_strequ(str[0], COLOR) ||
	ft_strequ(str[0], ROTATION)))
		tmp = ft_new_lst(str[0], ft_new_arr_i(str[1], str[2], str[3], NULL));
	else if (j == 5 && ft_strequ(str[0], ROTATION))
		tmp = ft_new_lst(str[0], ft_new_arr_i(str[1], str[2], str[3], str[4]));
	else
		tmp = NULL;
	ft_add_lst(lst, tmp);
}

void				ft_create_type(t_lst **lst, t_data *data,
					int *block, int *i)
{
	static t_arr_type	arr[] = ARR_TYPES;

	if (*lst != NULL)
		arr[*i].ft_create_type(data, *lst);
	*lst = NULL;
	ft_check_braces(block, 2);
}

void				ft_get_scene(int fd, t_data *data)
{
	char			*line;
	int				i;
	t_lst			*lst;
	int				block;
	int				status;

	lst = NULL;
	block = 0;
	while ((status = get_next_line(fd, &line)) > 0)
	{
		while (ft_isspace(*line) == 1)
			line++;
		if (*line == '\0' || ft_is_hash(line, &i) == 1)
			continue ;
		if (*line == '{')
			ft_check_braces(&block, 1);
		else if (*line == '}')
			ft_create_type(&lst, data, &block, &i);
		else if (block == 1)
			ft_get_data(&lst, line);
	}
	if (status == -1)
		ft_print(ft_msg(ERROR_33));
	ft_check_braces(&block, 3);
	ft_create_scene_objects(data);
}
