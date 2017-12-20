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

void	remove_figure(char ***field, t_list *list, int i, int j)
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

void	add_elem_in_field(char ***field, t_list *list, int i, int j)
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

int		check_in_field(char **field, t_list *list, int i, int j)
{
	int k;
	int num;

	k = 0;
	num = 0;
	while ((*field)[num] != 0)
		num++;
	while (k < 4)
	{
		if (i + ((t_coordinate *)(list->content))[k].y < num && j +
		((t_coordinate *)(list->content))[k].x < num &&
		field[i + (((t_coordinate *)(list->content))[k].y)][j +
		(((t_coordinate *)(list->content))[k].x)] == '.')
			k++;
		else
			break ;
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

void	if_solution(char ***field, t_list **list, int num)
{
	int	k;

	k = 0;
	while ((*field)[k])
	{
		ft_putstr((*field)[k]);
		write(1, "\n", 1);
		k++;
	}
	ft_lstdel(list);
	free_mem((*field), num);
}

int		fill_field(char ***field, t_list *list, int blocks, int num)
{
	int		i;
	int		j;

	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < num)
		{
			if (check_in_field(*field, list, i, j) == 1)
			{
				add_elem_in_field(field, list, i, j);
				if (list->content_size == (size_t)blocks - 1)
				{
					if_solution(field, &list, num);
					return (1);
				}
				if (fill_field(field, list->next, blocks, num))
					return (1);
				remove_figure(field, list, i, j);				
			}
			j++;
		}
		i++;
	}
	return (0);
}
