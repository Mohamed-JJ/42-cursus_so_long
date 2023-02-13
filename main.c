/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:36:13 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/13 19:08:30 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	str_chr_full(char *where_to_look, char *to_find) // to check for a string inside of another string
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
	mlx_destroy_window(param->mlx, param->win); // this function destroys the window
	exit(0); // exit the program
	return (0);
}

int	map_ber(t_mlx *v, char *str) // the function that we check the extention of the file we pass as an argumet has an extention that we are not allowed to use
{
	int	fd;

	if (str_chr_full(str, ".ber") == 0)
		return (0);
	fd = open(str, O_RDWR); // to open the file descriptor after checking the xtention to read the file
	v->str = get_next_line(fd); // get_next_line returns a string with its new lines, but in your case you should read line by line in case a new line was the only thing in the file or in the middle of the file
	v->arr = ft_split(v->str, '\n'); // split the returned string by new line
	return (1);
}

int	main(int ac, char **av)
{
	t_mlx	*v;

	v = malloc(sizeof(t_mlx));
	if (!v) // to protect our program in case of a seg fault
		return (0);
	if (ac < 2) // in case the path to the map was not passed
		return (write(1, "not enough arguments", 19), 0);
	if (map_ber(v, av[1]) == 0) // to check the map extention if it is valid or not . what to compare it to is .ber
		return (write(1, "bad map extention", 17), 0);
	if (check_map(v) == 0) // to check if there is is an error in map, like an irrelevent character, or an extra line or any kind of error
		return (write(1, "there is an error in the map", 28), 0);
	if (back_tracking(v) == 0) // this is to check if there is a winnable path that the player can take to win the game, otherwise the game wont be playable
		return (ft_putstr("there is no valid path"), 0);
	v->columns = get_arr_len(v->arr); // this is to get the number of rows. it needs to be taken in order to initialize the window
	v->row = ft_strlen(v->arr[0]); // the case here as above
	v->mlx = mlx_init(); //the mlx_init function returns a void pointer which has the address of the process which is used for multiple things like looping infinitly 
	v->win = mlx_new_window(v->mlx, v->row * 32, v->columns * 32, "so_long"); // to create our window which we will use it to draw on it
	mlx_loop_hook(v->mlx, draw_map, v); // to repeat some everytime mlx is invoked
	mlx_hook(v->win, 2, 0, check_key_and_print, v); // the function that we use to repeat an action each time a kep is pressed
	mlx_hook(v->win, 17, 0, ft_destroy, v); // we use it to close the window in case we clicked on the red mark at the top of the window
	mlx_loop(v->mlx); // the function that is used to run infinitly
	return (0);
}
