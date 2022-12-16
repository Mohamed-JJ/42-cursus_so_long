/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 17:17:23 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/16 22:35:01 by mjarboua         ###   ########.fr       */
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

int	canMove(char **v, int x, int y)
{
	int	x_len;
	int	y_len;

	x_len = ft_strlen(v[0]);
	y_len = get_arr_len(v);
	if (x >= 0 && x < x_len && y >= 0 && y < y_len && v[y][x] != '1')
		return (1);
	return (0);
}

int	find_path(char **v, int x, int y)
{
	static int e;
	static int c;
	for (int i = 0; i < get_arr_len(v); i++) {
		printf("%s\n", v[i]);
	}
	printf("\n");
	if (v[y][x] == 'E')
		e++;
	if (v[y][x] == 'C')
		c++;
	v[y][x] = '1';
	if (canMove(v, x - 1, y)) 
		find_path(v, x - 1, y);
	if (canMove(v, x, y + 1))
		find_path(v, x, y + 1);
	if (canMove(v, x + 1, y))
		find_path(v, x + 1, y);
	if (canMove(v, x, y - 1)) 
		find_path(v, x, y - 1);
	if (e > 0  && c == 2)
		return 1;
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
	if (find_path(arr, p_x, p_y) != 1)
		write (1, "there is no valid path", 23);
	else
		write (1, "there is a valid path", 22);
	int r = get_arr_len(arr);
	while (r >= 0)
	{
		free(arr[r]);
		free(str[r]);
		r--;
	}
	free(arr);
	free(str);
	while (1);
	return (0);
}
