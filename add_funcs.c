#include "fillit_header.h"

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			write(1, &(*(s + i)), 1);
			i++;
		}
	}
}

int	ft_sqrt(int nb)
{
	int d;

	if (nb <= 0)
		return (0);
	while (nb)
	{
		d = 1;
		while (d <= nb / 2)
		{
			if (d * d == nb)
				return (d);
			d++;
		}
		nb++;
	}
	return (0);
}

char	***multi_arr_mem(int n, int r, int w)
{
	int		i;
	int		j;
	char	***multi_arr;
	char	*data;
	char	**ptr;

	i = 0;
	j = 0;
	multi_arr = (char ***)malloc(sizeof(char **) * n +
		sizeof(char *) * n * r + n * r * w);
	ptr = (char **)(multi_arr + n);
	data = (char *)(multi_arr + n + n * r);
	while (i < n)
	{
		multi_arr[i] = ptr + i * r;
		j = 0;
		while (j < r)
		{
			multi_arr[i][j] = data + i * r * w + j * w;
			multi_arr[i][j][w - 1] = 0;
			j++;
		}
		i++;
	}
	return (multi_arr);
}

int	to_multi_arr(char *buf, char ****multi_arr, int strings, int symbols)
{
	int i;
	int j;
	int k;
	int l;

	i = 0;
	l = 0;
	while (buf[l] != 0)
	{
		j = 0;
		while (j < strings)
		{
			k = 0;
			while (k < symbols)
			{
				(*multi_arr)[i][j][k] = buf[l++];
				k++;
			}
			l++;
			j++;
		}
		l++;
		i++;
	}
	return (i);
}
