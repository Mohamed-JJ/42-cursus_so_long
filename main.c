/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:36:13 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/17 22:09:57 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	str_chr_full(char *where_to_look, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!to_find || !where_to_look)
		return (0);
	while (where_to_look[i])
	{
		if (where_to_look[i] == to_find[j]
			&& where_to_look[i + 1] == to_find[j + 1])
		{
			while (to_find[j])
			{
				if (where_to_look[i] != to_find[j]
					&& j < (int)ft_strlen(to_find))
					return (0);
				i++;
				j++;
			}
		}
		i++;
	}
	return (1);
}

int	ft_destroy(t_mlx *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit(0);
	return (0);
}

int	map_ber(t_mlx *v, char *str)
{
	int	fd;

	if (str_chr_full(str, ".ber") == 0)
		return (0);
	fd = open(str, O_RDWR);
	v->str = get_next_line(fd);
	v->arr = ft_split(v->str, '\n');
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx	*v;

	v = malloc(sizeof(t_mlx));
	if (!v)
		return (0);
	if (ac < 2)
		return (write(1, "not enough arguments", 19), 0);
	if (map_ber(v, av[1]) == 0)
		return (write(1, "bad map extention", 17), 0);
	if (check_map(v) == 0)
		return (write(1, "there is an error in the map", 28), 0);
	if (back_tracking(v) == 0)
		return (ft_putstr("there is no valid path"), 0);
	v->columns = get_arr_len(v->arr);
	v->row = ft_strlen(v->arr[0]);
	v->mlx = mlx_init();
	v->win = mlx_new_window(v->mlx, v->row * 32, v->columns * 32, "so_long");
	mlx_loop_hook(v->mlx, draw_map, v);
	mlx_hook(v->win, 2, 0, check_key_and_print, v);
	mlx_hook(v->win, 17, 0, ft_destroy, v);
	mlx_loop(v->mlx);
	return (0);
}
