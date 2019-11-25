/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:22:41 by jwisozk           #+#    #+#             */
/*   Updated: 2019/10/13 14:19:07 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_gc		*ft_gc_create(void)
{
	t_gc *vector;

	vector = malloc(sizeof(t_gc));
	ft_bzero(vector, sizeof(t_gc));
	if (vector)
	{
		vector->len = GC_SIZE;
		vector->size = sizeof(size_t *);
		vector->data = malloc(vector->size * GC_SIZE);
	}
	return (vector);
}

void		ft_gc_clean(t_gc **vector)
{
	size_t size;

	if (*vector)
	{
		size = (*vector)->count;
		while (size--)
			free((*vector)->data[size]);
		free((*vector)->data);
		free(*vector);
	}
}

void		ft_gc_resize(t_gc **vector)
{
	void		**temp;
	void		**vec_data;
	ssize_t		size;

	if (*vector)
	{
		temp = (*vector)->data;
		size = (*vector)->len * (*vector)->size;
		if (!(vec_data = malloc(size * 2)))
		{
			ft_gc_clean(vector);
			ft_putendl_fd(GC_ERROR, 2);
			exit(0);
		}
		vec_data = ft_memmove(vec_data, temp, size);
		free(temp);
		(*vector)->data = vec_data;
		(*vector)->len = (*vector)->len * 2;
	}
}

void		ft_gc_add(t_gc **vector, void *data)
{
	if (*vector)
	{
		if ((*vector)->len - (*vector)->count <= 1)
			ft_gc_resize(vector);
		(*vector)->data[(*vector)->count] = data;
		++(*vector)->count;
	}
}
