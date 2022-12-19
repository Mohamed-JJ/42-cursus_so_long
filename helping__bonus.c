/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helping__bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 21:03:28 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/18 21:14:19 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long__bonus.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < 10)
		ft_putchar(nbr + '0');
	else
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

int	get_arr_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**allocate_clone(char **v)
{
	int		i;
	int		j;
	char	**str;

	j = 0;
	i = 0;
	str = malloc(sizeof(char *) * (get_arr_len(v) + 1));
	while (v[i])
	{
		str[i] = ft_strdup(v[i]);
		i++;
	}
	str[i] = NULL;
	return (str);
}
