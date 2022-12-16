/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_draw_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:15:18 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/04 11:53:43 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_draw_map(char *str)
{
	char	**s;

	s = ft_split(str, '\n');
	var.i = 0;
	var.x = 0;
	while (s[var.i])
	{
		var.j = 0;
		var.y = 0;
		while (s[var.i][var.j])
		{
			if (s[var.i][var.j] == 'P')
				draw_player(var.x, var.y);
			else if (s[var.i][var.j] == 'E')
				draw_exit(var.x, var.y);
			else if (s[var.i][var.j] == 'C')
				draw_coll(var.x, var.y);
			else
				draw_wall(var.x, var.y);
			var.j++;
			var.y++;
		}
		var.x++;
		var.i++;
	}
}