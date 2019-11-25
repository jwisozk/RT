/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twill <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 17:23:06 by jwisozk           #+#    #+#             */
/*   Updated: 2019/10/13 13:47:18 by twill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GC_H
# define FT_GC_H
# define GC_SIZE	16777216
# define GC_ERROR	"Array of pointers is overflow."

typedef struct		s_gc
{
	ssize_t			count;
	ssize_t			len;
	ssize_t			size;
	void			**data;
}					t_gc;

void				ft_gc_clean(t_gc **vector);
void				ft_gc_add(t_gc **vector, void *d);
t_gc				*ft_gc_create(void);

#endif
