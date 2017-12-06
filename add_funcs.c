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