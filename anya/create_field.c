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

#include <stdio.h>
//#include "libft.h"
#include "fillit.h"

int		count_blocks(int blocks)
{
	int num;

	num = ft_sqrt(blocks * 4);
	return (num);
}

char	**create_field(int num)
{
	int 	i;
	int 	j;
	char	**field;
	// int 	num;

	i = 0;
	// num = ft_sqrt(blocks * 4);
	field = (char **)malloc(sizeof(char *) * (num + 1));
	field[num] = NULL;
	while (i < num)
	{
		field[i] = (char*)malloc(sizeof(char) * (num + 1));
		i++;
	}
	i = 0;
	while (i < num)
	{
		j = 0;
		while (j < num)
		{
			field[i][j] = '.';
			j++;
		}
		field[i][j] = '\0';
		i++;
	}
	return (field);
}
	// printf("%d\n %d\n", i, j);
	// while (i--)
	// 	printf("%s\n", field[i]);

	void	printvika(t_list *vika)
{
	int i;

	while (vika)
	{
		i = 0;
		while (i < 4)
		{
			printf("contentx %d\n", ((t_coordinate *)(vika->content))[i].x);
			printf("contenty %d\n\n", ((t_coordinate *)(vika->content))[i].y);
			i++;
		}
		//printf("contentx %s\n", ((char *)(vika->content)));
		vika = vika->next;
	}
}

int	check_in_field(char **field, t_list *list, int i, int j, int num)
{
	int k;
	printf("%d\n", 2);
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
	printf("%d\n", 3);
	printvika(list);
	if (k < 4 && (i + ((t_coordinate *)(list->content))[k].y >= num || j +
	((t_coordinate *)(list->content))[k].x >= num))
		return (-1);
	if (k < 4 && (field[i + (((t_coordinate *)(list->content))[k].y)][j +
	(((t_coordinate *)(list->content))[k].x)] != '.'))
			return (0);
	else
		return (1);
}

char **free_mem(char **field, int num)
{
	int i;

	i = 0;
	while (i <= num)
	{
		free(field[i]);
		field[i] = NULL;
		i++;
	}
	free(field);
	field = NULL;
	return (field);
}

void remove_figure(char ***field, t_list *list, int i, int j, int blocks)
{
	int k;

	k = 0;
	while (k < blocks)
	{
		(*field)[i + (((t_coordinate *)(list->content))[k].y)][j + (((t_coordinate *)(list->content))[k].x)] = '.';
				k++;
	}
}

int		fill_field(int i, char **field, t_list *list, int blocks, int num)
{
	//int i;
	int j;
	int z;
	int result;
	printf("%d\n", 1);
	//i = 0;
	//z = 0;
	result = 0;
	while (j < num)
	{
		if (field[i][j] == '.' && check_in_field(field, list, i, j, num) == 1)
		{
				add_elem_in_field(&field, list, i, j, blocks);
				//printvika(list);
				if (list->content_size == blocks - 1)
					result = 1;
		}
		else
		{
				if (check_in_field(field, list, i, j, num) == -1)
				{
					//return (2);
					free_mem(field, num);
					field = create_field(num + 1);
					num++;
					i = 0;
					fill_field(i, field, list, blocks, num);
				}
				else
					if (!(result = fill_field(i + 1, field, list->next, blocks, num)))
						remove_figure(&field, list, i, j, blocks);
		}
		if (result)
      break;
		++j;
	}
	return (result);
}

void add_elem_in_field(char ***field, t_list *list, int i, int j, int blocks)
{
	int k;

	k = 0;
	while (k < 4)
	{
		(*field)[i + (((t_coordinate *)(list->content))[k].y)][j + (((t_coordinate *)(list->content))[k].x)] =
		 	'A' + list->content_size;
				++k;
	}
	k = 0;
	while (field)
		printf("%s\n", (*field)[k++]);
}
