/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 20:44:10 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/08 20:44:10 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	coordinatemin(t_coordinate c[4])
{
	int minx;
	int miny;
	int i;

	i = 0;
	minx = 3;
	miny = 3;
	while (i < 4)
	{
		if (c[i].x < minx)
			minx = c[i].x;
		if (c[i].y < miny)
			miny = c[i].y;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		c[i].x = c[i].x - minx;
		c[i].y = c[i].y - miny;
		i++;
	}
}

void	list_push_back(t_list **begin_list, t_list *new)
{
	t_list *list;

	list = *begin_list;
	if (!list)
	{
		*begin_list = new;
		return ;
	}
	while (list->next)
		list = list->next;
	list->next = new;
}

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new_list;

	new_list = NULL;
	if (!(new_list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(new_list->content = malloc(content_size)))
		{
			free(new_list);
			new_list = NULL;
			return (NULL);
		}
		ft_memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
	}
	else
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	new_list->next = NULL;
	return (new_list);
}

void	save_coordinateone(char *s, t_list **list, int *i, int blocks)
{
	int				countx;
	int				county;
	int				arr;
	t_list			*oneelem;
	t_coordinate	c[4];

	countx = 0;
	county = 0;
	arr = 0;
	while (s[*i] && county < 4)
	{
		if (s[*i] == '\n' && countx == 4)
		{
			county++;
			countx = 0;
			*i += 1;
		}
		if (s[*i] == '#')
		{
			c[arr].x = countx;
			c[arr++].y = county;
		}
		(s[*i] != '\0' && county != 4) ? *i += 1 : *i;
		countx++;
	}
	coordinatemin(c);
	oneelem = ft_lstnew(c, sizeof(t_coordinate) * 4);
	oneelem->content_size = blocks;
	list_push_back(&(*list), oneelem);
}

t_list	*coordinate(char *s, int *blocks)
{
	int		i;
	t_list	*list;

	i = 0;
	list = NULL;
	*blocks = 0;
	while (s[i])
	{
		save_coordinateone(s, &list, &i, *blocks);
		(*blocks)++;
		(s[i]) ? i++ : i;
	}
	free(s);
	return (list);
}
