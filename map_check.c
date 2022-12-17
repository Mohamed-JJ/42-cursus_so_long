/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:31:35 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/17 19:40:17 by mjarboua         ###   ########.fr       */
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

int	check_p_e(t_mlx *v)
{
	int	e;
	int	p;
	int	j;
	int	i;

	i = -1;
	e = 0;
	p = 0;
	v->coins = 0;
	while (v->arr[++i])
	{	
		j = -1;
		while (v->arr[i][++j])
		{
			if (v->arr[i][j] == 'E')
				e++;
			else if (v->arr[i][j] == 'P')
				p++;
			else if (v->arr[i][j] == 'C')
				v->coins++;
		}
	}
	if (e == 1 && p == 1 && v->coins > 0)
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

int	check_map(t_mlx *v)
{
	if (check_wall(v->arr) == 0 || check_p_e(v) == 0
		|| check_len(v->arr) == 0 || check_f_l(v->arr) == 0)
		return (0);
	return (1);
}
