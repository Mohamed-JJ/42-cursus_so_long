/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing2__bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:28:44 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/18 21:13:49 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long__bonus.h"

void	draw_down(t_mlx *v, int *moves)
{
	if (v->arr[v->p_i][v->p_j] == 'P')
	{
		if (v->arr[v->p_i + 1][v->p_j] == '1')
			v->arr[v->p_i][v->p_j] = 'P';
		else if ((v->arr[v->p_i + 1][v->p_j] == 'E' && check_coins(v->arr))
				|| v->arr[v->p_i + 1][v->p_j] == 'A')
		{
			if (v->arr[v->p_i + 1][v->p_j] == 'A')
				ft_putstr("busted");
			else
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

void	draw_up(t_mlx *v, int *moves)
{
	if (v->arr[v->p_i][v->p_j] == 'P')
	{
		if (v->arr[v->p_i - 1][v->p_j] == '1')
			v->arr[v->p_i][v->p_j] = 'P';
		else if ((v->arr[v->p_i - 1][v->p_j] == 'E' && check_coins(v->arr))
				|| v->arr[v->p_i - 1][v->p_j] == 'A')
		{
			if (v->arr[v->p_i - 1][v->p_j] == 'A')
				ft_putstr("busted");
			else
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

void	draw_left(t_mlx *v, int *moves)
{
	if (v->arr[v->p_i][v->p_j] == 'P')
	{
		if (v->arr[v->p_i][v->p_j - 1] == '1')
			v->arr[v->p_i][v->p_j] = 'P';
		else if ((v->arr[v->p_i][v->p_j - 1] == 'E' && check_coins(v->arr))
				|| v->arr[v->p_i][v->p_j - 1] == 'A')
		{
			if (v->arr[v->p_i][v->p_j - 1] == 'A')
				ft_putstr("busted");
			else
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

void	draw_right(t_mlx *v, int *moves)
{
	if (v->arr[v->p_i][v->p_j] == 'P')
	{
		if (v->arr[v->p_i][v->p_j + 1] == '1')
			v->arr[v->p_i][v->p_j] = 'P';
		else if ((v->arr[v->p_i][v->p_j + 1] == 'E' && check_coins(v->arr))
				|| v->arr[v->p_i][v->p_j + 1] == 'A')
		{
			if (v->arr[v->p_i][v->p_j + 1] == 'A')
				ft_putstr("busted");
			else
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
