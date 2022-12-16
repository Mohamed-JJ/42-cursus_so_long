/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:34:31 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/06 20:36:59 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void	draw_up(t_mlx *v, int *x, int *y)
{
	// mlx_destroy_image(v->mlx, v->img);
	size_t i = 0, j = 0;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 13; j++) {
			if (v->arr[i][j] == 'P')
				goto out;
		}
	}
	out:
	v->arr[i][j] = '0';
	i--;
	v->arr[i][j] = 'P';
	
	// v->img = mlx_xpm_file_to_image(v->mlx,
	// 		"./resources/flopy.xpm", &v->width, &v->height);
	// mlx_put_image_to_window(v->mlx, v->win, v->img, v->x, v->y);
}