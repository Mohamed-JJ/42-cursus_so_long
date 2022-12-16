/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:03:42 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/14 21:45:25 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_key_and_print(int key, void *param)
{
	t_mlx		*v;
	static int	i;

	v = (t_mlx *)param;
	if (key == 53)
	{
		ft_putstr("game has eneded");
		exit (0);
	}
	else if (key == 13)
		draw_up(v);
	else if (key == 1)
		draw_down(v);
	else if (key == 0)
		draw_left(v);
	else if (key == 2)
		draw_right(v);
	if (key == 13 || key == 1 || key == 0 || key == 2)
	{
		ft_putnbr(i++);
		ft_putchar('\n');
	}
	return (0);
}
