/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:28:44 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/16 19:29:29 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_coins(char **str)
{
	int	j;
	int	i;
	int	x;

	i = 0;
	j = 0;
	while (str[i])
	{
		x = 0;
		while (str[i][x])
		{
			if (str[i][x] == 'C')
				j++;
			x++;
		}
		i++;
	}
	if (j == 0)
		return (1);
	return (0);
}

void	draw_down(t_mlx *v,int *moves)
{
	if (v->arr[v->p_i][v->p_j] == 'P')
	{
		if (v->arr[v->p_i + 1][v->p_j] == '1')
			v->arr[v->p_i][v->p_j] = 'P';
		else if (v->arr[v->p_i + 1][v->p_j] == 'E' && check_coins(v->arr))
		{
			ft_putstr("game won");
			exit (0);
		}
		else if (v->arr[v->p_i + 1][v->p_j] == 'E' && v->coins != 0)
			v->arr[v->p_i][v->p_j] = 'P';
		else
		{
			v->arr[v->p_i][v->p_j] = '0';
			v->p_i++;
			v->arr[v->p_i][v->p_j] = 'P';
			*moves += 1;
			ft_putnbr(*moves);
			ft_putstr("\n");
		}
	}
}

void	draw_up(t_mlx *v,int *moves)
{
	if (v->arr[v->p_i][v->p_j] == 'P')
	{
		if (v->arr[v->p_i - 1][v->p_j] == '1')
			v->arr[v->p_i][v->p_j] = 'P';
		else if (v->arr[v->p_i - 1][v->p_j] == 'E' && check_coins(v->arr))
		{
			ft_putstr("game won");
			exit (0);
		}
		else if (v->arr[v->p_i - 1][v->p_j] == 'E' && v->coins != 0)
			v->arr[v->p_i][v->p_j] = 'P';
		else
		{
			v->arr[v->p_i][v->p_j] = '0';
			v->p_i--;
			v->arr[v->p_i][v->p_j] = 'P';
			*moves += 1;
			ft_putnbr(*moves);
			ft_putstr("\n");
		}
	}
}

void	draw_left(t_mlx *v,int *moves)
{
	if (v->arr[v->p_i][v->p_j] == 'P')
	{
		if (v->arr[v->p_i][v->p_j - 1] == '1')
			v->arr[v->p_i][v->p_j] = 'P';
		else if (v->arr[v->p_i][v->p_j - 1] == 'E' && check_coins(v->arr))
		{
			ft_putstr("game won");
			exit (0);
		}
		else if (v->arr[v->p_i][v->p_j - 1] == 'E' && v->coins != 0)
			v->arr[v->p_i][v->p_j] = 'P';
		else
		{
			v->arr[v->p_i][v->p_j] = '0';
			v->p_j--;
			v->arr[v->p_i][v->p_j] = 'P';
			*moves += 1;
			ft_putnbr(*moves);
			ft_putstr("\n");
		}
	}
}

void	draw_right(t_mlx *v,int *moves)
{
	if (v->arr[v->p_i][v->p_j] == 'P')
	{
		if (v->arr[v->p_i][v->p_j + 1] == '1')
			v->arr[v->p_i][v->p_j] = 'P';
		else if (v->arr[v->p_i][v->p_j + 1] == 'E' && check_coins(v->arr))
		{
			ft_putstr("game won");
			exit (0);
		}
		else if (v->arr[v->p_i][v->p_j + 1] == 'E' && v->coins != 0)
			v->arr[v->p_i][v->p_j] = 'P';
		else
		{
			v->arr[v->p_i][v->p_j] = '0';
			v->p_j++;
			v->arr[v->p_i][v->p_j] = 'P';
			*moves += 1;
			ft_putnbr(*moves);
			ft_putstr("\n");
		}
	}
}
