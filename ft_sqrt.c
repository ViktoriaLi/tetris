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
	/*while (d <= nb / 2)
	{
		if (d * d == nb)
			return (d);
		d++;
		else
		{
			d = 1;
			nb++;
			while (d <= nb / 2)
			{
				if (d * d == nb)
					{
						return (d);
						break ;
					}
				d++;
			}

		}
	}*/
	return (0);
}
