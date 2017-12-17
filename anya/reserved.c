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
