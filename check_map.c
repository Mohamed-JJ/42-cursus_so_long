/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:40:21 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/06 20:31:58 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_len(char **str)
{
	size_t	x;

	x = ft_strlen(str[0]);
	while (*str)
	{
		if (ft_strlen(*str) != x)
			return (0);
		str++;
	}
	return (1);
}

int	check_wall(char **str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i])
	{
		if (str[i][0] != '1' || str[i][ft_strlen(str[i]) - 1] != '1')
			return (0);
	}
	return (1);
}

int	check_p_e(char *str)
{
	int	e;
	int	p;
	int	c;

	e = 0;
	p = 0;
	c = 0;
	while (*str)
	{
		if (*str == 'E')
			e++;
		else if (*str == 'P')
			p++;
		else if (*str == 'C')
			c++;
		str++;
	}
	if (e == 1 && p == 1 && c > 0)
		return (1);
	return (0);
}

int	check_f_l(char **s)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while (s[0][i])
	{
		if (s[0][i++] != '1')
			return (0);
	}
	while (s[x])
		x++;
	x--;
	i = -1;
	while (s[x][++i])
	{
		if (s[x][i] != '1')
			return (0);
	}
	return (1);
}

int	check_map(char *str)
{
	char	**s;

	s = ft_split(str, '\n');
	if (check_wall(s) == 0 || check_p_e(str) == 0
		|| check_len(s) == 0 || check_f_l(s) == 0)
		return (0);
	return (1);
}
