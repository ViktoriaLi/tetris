char **two_dim_arr_mem(char **field, int numb, char c)
{
	int i;
	int j;

	i = 0;
	field = (char **)malloc(sizeof(char *) * numb);
	while (i < numb)
	{
		field[i] = (char *)malloc(numb);
		i++;
	}
	i = 0;
	while (i < numb)
	{
		j = 0;
		while (j < numb)
		{
			field[i][j] = c;
			j++;
		}
		i++;
	}
	return (field);
}
