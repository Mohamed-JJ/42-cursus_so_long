/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:03:42 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/16 19:31:40 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_player(char **str)
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
				if (str[i + 1][j] == '1')
					return (0);
				if (str[i - 1][j] == '1')
					return (0);
				if (str[i][j + 1] == '1')
					return (0);
				if (str[i][j - 1] == '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_key_and_print(int key, void *param)
{
	static int	moves;
	t_mlx		*v;

	v = (t_mlx *)param;
	if (key == 53)
	{
		ft_putstr("game has eneded");
		exit (0);
	}
	else if (key == 13)
		draw_up(v, &moves);
	else if (key == 1)
		draw_down(v, &moves);
	else if (key == 0)
		draw_left(v, &moves);
	else if (key == 2)
		draw_right(v, &moves);
	return (0);
}
