/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 20:53:16 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/17 21:07:13 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_things(t_mlx *v, char c)
{
	if (c == '1')
	{
		v->img = mlx_xpm_file_to_image(v->mlx,
				"./r/wall.xpm", &v->width, &v->height);
		mlx_put_image_to_window(v->mlx, v->win, v->img, v->y, v->x);
	}
	else if (c == 'P')
	{
		v->img = mlx_xpm_file_to_image(v->mlx,
				"./r/flopy.xpm", &v->width, &v->height);
		mlx_put_image_to_window(v->mlx, v->win, v->img, v->y, v->x);
	}
	else if (c == 'C')
	{
		v->img = mlx_xpm_file_to_image(v->mlx,
				"./r/coll.xpm", &v->width, &v->height);
		mlx_put_image_to_window(v->mlx, v->win, v->img, v->y, v->x);
	}
	else if (c == 'E')
	{
		v->img = mlx_xpm_file_to_image(v->mlx,
				"./r/exit.xpm", &v->width, &v->height);
		mlx_put_image_to_window(v->mlx, v->win, v->img, v->y, v->x);
	}
}

int	draw_map(t_mlx *v)
{
	int	i;
	int	j;

	i = -1;
	v->x = 0;
	mlx_clear_window(v->mlx, v->win);
	while (v->arr[++i])
	{
		j = -1;
		v->y = 0;
		while (v->arr[i][++j])
		{
			if (v->arr[i][j] == 'P')
			{
				v->p_i = i;
				v->p_j = j;
			}
			if (v->arr[i][j] != '0')
				draw_things(v, v->arr[i][j]);
			v->y += 32;
		}
		v->x += 32;
	}
	return (0);
}
