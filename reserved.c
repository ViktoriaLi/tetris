void paste_figure(char **all_blocks, char ***field, int l, int m)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (all_blocks[i][j] != '*' && j < 4)
			j++;
		while (j < 4)
		{
			if (j < 3 && all_blocks[i][j + 1] == '*')
			 	(*field)[l][m + 1] = all_blocks[i][j + 1];
			if (j > 0 && all_blocks[i][j - 1] == '*')
				(*field)[l][m - 1] = all_blocks[i][j - 1];
			if (i < 3 && all_blocks[i + 1][j] == '*')
				 (*field)[l + 1][m] = all_blocks[i + 1][j];
			if (i > 0 && all_blocks[i - 1][j] == '*')
				 (*field)[l - 1][m] = all_blocks[i - 1][j];
			j++;
			m++;
		}
		i++;
		l++;
	}
}

int check_place(char **all_blocks, char **field, int l, int m)
{
	int i;
	int j;
	int place;

	i = 0;
	j = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			while (all_blocks[i][j] != '*' && j < 4)
				j++;
			place++;
			if (j < 3 && all_blocks[i][j + 1] == '*' && field[l][m + 1] == '.')
				place++;
			if (j > 0 && all_blocks[i][j - 1] == '*' && field[l][m - 1] == '.')
				place++;
			if (i < 3 && all_blocks[i + 1][j] == '*' && field[l + 1][m] == '.')
					place++;
			if (i > 0 && all_blocks[i - 1][j] == '*' && field[l - 1][m] == '.')
					place++;
			j++;
			m++;
		}
		i++;
		l++;
	}
	printf("place %d\n", place);
	return (place);
}
