/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdanylov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 15:57:23 by gdanylov          #+#    #+#             */
/*   Updated: 2017/12/10 15:57:24 by gdanylov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_in_field(char **field, t_list *list, int i, int j, int num)
{
	int k;

	k = 0;
	while (k < 4)
	{
		if (i + ((t_coordinate *)(list->content))[k].y < num && j +
		((t_coordinate *)(list->content))[k].x < num &&
		field[i + (((t_coordinate *)(list->content))[k].y)][j +
		(((t_coordinate *)(list->content))[k].x)] == '.')
			k++;
		else
			break;
	}
	if (k < 4 && (i + ((t_coordinate *)(list->content))[k].y >= num || j +
		((t_coordinate *)(list->content))[k].x >= num))
		return (-1);
	if (k < 4 && (field[i + (((t_coordinate *)(list->content))[k].y)][j +
		(((t_coordinate *)(list->content))[k].x)] != '.'))
		return (0);
	else
		return (1);
}

void remove_figure(char ***field, t_list *list, int i, int j)
{
	int k;

	k = 0;
	while (k < 4)
	{
		(*field)[i + (((t_coordinate *)(list->content))[k].y)][j +
			(((t_coordinate *)(list->content))[k].x)] = '.';
		k++;
	}
}

int		fill_field(char ***field, t_list *list, int blocks)
{
	int i;
	int j;
	int k;
	int num;
	t_list *head;

	i = 0;
	k = 0;
	num = 0;
	head = list;
	while ((*field)[num] != 0)
		num++;
	while (i < num)
	{
		j = 0;
		while (j < num)
		{
			if (check_in_field(*field, list, i, j, num) == 1)
			{
				add_elem_in_field(field, list, i, j);
				if (list->content_size == (size_t)blocks - 1)
				{
					while ((*field)[k])
					{
						ft_putstr((*field)[k]);
						write(1, "\n", 1);
						k++;
					}
					ft_lstdel(&head);
					free_mem((*field), num);
					return (1);
				}
				if (fill_field(field, list->next, blocks))
					return (1);
				else
				{
					remove_figure(field, list, i, j);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

void add_elem_in_field(char ***field, t_list *list, int i, int j)
{
	int k;

	k = 0;
	while (k < 4)
	{
		(*field)[i + (((t_coordinate *)(list->content))[k].y)][j + 
			(((t_coordinate *)(list->content))[k].x)] =
		 	'A' + list->content_size;
		++k;
	}
}
