/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:51:30 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/16 15:23:36 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	get_arr_len(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	issafe(char **v, int x, int y)
{
	int	x_len;
	int	y_len;

	x_len = ft_strlen(v[0]);
	y_len = get_arr_len(v);
	if (x >= 0 && x < x_len && y >= 0
		&& y < y_len && (v[y][x] ==  '0' || v[y][x] == 'C'))
		return (1);

	return (0);
}

int	solvemazeutil(char **v, int x, int y, char c)
{
	int	x_len;
	int	y_len;

	x_len = ft_strlen(v[0]);
	y_len = get_arr_len(v);
	if (v[y][x] == c)
		return (1);
	if (issafe(v, x, y) == 1)
	{
		v[y][x] = '1';

		if (solvemazeutil(v, x + 1, y, c) == 1)
			return (1);
		if (solvemazeutil(v, x - 1, y, c) == 1)
			return (1);
		if (solvemazeutil(v, x, y + 1, c) == 1)
			return (1);
		if (solvemazeutil(v, x, y - 1, c) == 1)
			return (1);
		v[y][x] = '0';
		return (0);
	}

	return (0);
}


char	**back_tracking_tin(char **v)
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

void	get_player_pos(char **str, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				*y = i;
				*x = j;
				break ;
			}	
			j++;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		fd;
	char	**str;
	char	**arr;
	int		p_x;
	int		p_y;

	fd = open(av[1], O_RDWR);
	str = ft_split(get_next_line(fd), '\n');
	arr = back_tracking_tin(str);
	get_player_pos(arr, &p_x, &p_y);
	// printf("the x axis : %d\t the y axis : %d", p_x, p_y);
	if (solvemazeutil(arr, p_x, p_y, 'E') != 1)
		write (1, "there is no valid path", 23);
	else
		write (1, "there is a valid path", 22);
	return (0);
}
