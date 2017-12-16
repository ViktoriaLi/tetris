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
	char **new_field;

	k = 0;
	while (k < 4)
	{
		if (i + ((t_coordinate *)(list->content))[k].y < num && j +
		((t_coordinate *)(list->content))[k].x < num &&
		field[i + (((t_coordinate *)(list->content))[k].y)][j +
		(((t_coordinate *)(list->content))[k].x)] == '.')
				k++;
		if (i + ((t_coordinate *)(list->content))[k].y >= num || j +
		((t_coordinate *)(list->content))[k].x >= num)
			return (-1);
		//new_field = create_field(num + 1);
		if (field[i + (((t_coordinate *)(list->content))[k].y)][j +
		(((t_coordinate *)(list->content))[k].x)] != '.')
				return (0);
	}
	printvika(list);
	return (1);
	//((t_coordinate *)(list->content)[k].x);
	//((t_coordinate *)(list->content)[k].y);

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

void remove_figure(char ***field, t_list *list, int i, int j)
{
	int k;

	k = 0;
	while (k < 4)
	{
		(*field)[i + (((t_coordinate *)(list->content))[k].y)][j + (((t_coordinate *)(list->content))[k].x)] = '.';
				k++;
	}
}

int		fill_field(char **field, t_list *list, int blocks, int num)
{
	int i;
	int j;
	int z;
	int result;

	i = 0;
	z = 0;
	result = 0;
	while (i < num)
	{
		j = 0;
		while (j < num)
		{
			if (field[i][j] == '.')
			{
				if (check_in_field(field, list, i, j, num) == 1)
				{
					add_elem_in_field(&field, list, i, j);
					if (list->content_size == blocks - 1)
						result = 1;
					else
					{
						{
							if (check_in_field(field, list, i, j, num) == -1)
							{
								free_mem(field, num);
								field = create_field(num + 1);
								num++;
							}
							if (!(result = fill_field(field, list->next, blocks, num)))
								remove_figure(&field, list, i, j);
						}
					}
				}
			}
			if (result)
			{
				i = num;
				j = num;
			}
			j++;
		}
		i++;
	}
	return (result);
}

void add_elem_in_field(char ***field, t_list *list, int i, int j)
{
	//int x;
	//int y;
	int k;

	k = 0;
	while (k < 4)
	{
		(*field)[i + (((t_coordinate *)(list->content))[k].y)][j + (((t_coordinate *)(list->content))[k].x)] = 'A' + list->content_size;
				k++;
	}


	/*field[i][j] = list->content_size + 'A';
	while (i < 4)
	{
		x = c[i].x;
		y = c[i].y;
		// printf("printx %d\n printy %d\n", x, y);
		field[y][x] = 'A';
		i++;
	}*/
	k = 0;
	while (field)
		printf("%s\n", (*field)[k++]);
}
