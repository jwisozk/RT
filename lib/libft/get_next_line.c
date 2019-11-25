/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwisozk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:23:19 by jwisozk           #+#    #+#             */
/*   Updated: 2019/10/13 22:21:11 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_get_lst(t_list *lst, const int fd)
{
	size_t	f;

	f = (size_t)fd;
	while (lst != NULL)
	{
		if (lst->content_size == f)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

static char		*ft_get_str(const int fd, int *status)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	char	*str;
	ssize_t	ret;

	str = NULL;
	tmp = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(str = (tmp != NULL) ? ft_strjoin(tmp, buf) : ft_strdup(buf)))
		{
			*status = -1;
			break ;
		}
		ft_strdel(&tmp);
		tmp = str;
	}
	if (ret == -1)
		*status = -1;
	if (*status == -1)
		ft_strdel(&tmp);
	return (str);
}

static void		ft_deltmp(t_list **head, t_list **tmp)
{
	t_list	*lst;

	lst = *head;
	if (*head == *tmp)
		*head = (*tmp)->next;
	else
	{
		while (lst->next != *tmp)
			lst = lst->next;
		lst->next = (*tmp)->next;
	}
	ft_memdel((void **)tmp);
}

static int		ft_get_line(char *str, char **line, t_list **lst, t_list **tmp)
{
	char	*lt;
	char	*new;
	char	*end;

	end = NULL;
	if ((new = ft_strchr(str, '\n')) == NULL)
		lt = str;
	else
	{
		if (!(lt = ft_strsub(str, 0, new - str)) ||
			!(new = ft_strdup(new + 1)))
		{
			ft_strdel(&lt);
			ft_strdel(&str);
			ft_deltmp(lst, tmp);
			return (-1);
		}
		ft_strdel(&str);
		(*new != '\0') ? end = new : ft_strdel(&new);
	}
	(end != NULL) ? (*tmp)->content = end : ft_deltmp(lst, tmp);
	*line = lt;
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst = NULL;
	t_list			*tmp;
	int				status;
	char			*str;

	if ((fd < 3 && fd != 0) || line == NULL)
		return (-1);
	*line = NULL;
	status = 0;
	tmp = (lst != NULL) ? ft_get_lst(lst, fd) : NULL;
	str = (tmp != NULL) ? tmp->content : ft_get_str(fd, &status);
	if (status == -1)
		return (-1);
	if (str == NULL)
		return (0);
	if (tmp == NULL)
	{
		if (!(tmp = ft_lstnew(NULL, 1)))
			ft_strdel(&str);
		if (tmp == NULL)
			return (-1);
		tmp->content_size = (size_t)fd;
		ft_lstadd(&lst, tmp);
	}
	return (ft_get_line(str, line, &lst, &tmp));
}
