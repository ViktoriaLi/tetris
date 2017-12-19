/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlikhotk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:52:14 by vlikhotk          #+#    #+#             */
/*   Updated: 2017/10/24 16:31:10 by vlikhotk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

char	*ft_strnew(size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = NULL;
	if (!(dest = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		dest[i] = 0;
		i++;
	}
	dest[i] = 0;
	return (dest);
}

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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d_temp;
	unsigned char	*s_temp;

	i = 0;
	d_temp = NULL;
	s_temp = NULL;
	if (n != 0)
	{
		d_temp = (unsigned char *)dst;
		s_temp = (unsigned char *)src;
		while (i < n)
		{
			d_temp[i] = s_temp[i];
			i++;
		}
		dst = (void *)d_temp;
	}
	return (dst);
}
