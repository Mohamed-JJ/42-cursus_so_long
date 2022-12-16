/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:09:29 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/06 20:11:36 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_key(int key, void *param)
{
	t_mlx	*var;

	var = (t_mlx *) param;
	if (key == 53)
	{
		write(1, "game ended", 10);
		exit(0);
	}
	else
	{
	if (key == 13)
	{
		
		draw_up(var, &var->x, &var->y);
	}
	// else if (key == 1)
	// 	draw_down(var);
	// else if (key == 2)
	// 	draw_right(var);
	// else if (key == 0)
	// 	draw_left(var);
	}
	ft_putnbr(key);
	write(1, "\n", 1);
	return (0);
}