/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:20:08 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/06 13:31:00 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_putchar(char s)
{
	write(1, &s, 1);
}

void	ft_putnbr(int s)
{
	if (s < 0)
	{
		ft_putchar('-');
		s *= -1;
	}
	if (s < 10)
		ft_putchar(s + '0');
	else
	{
		ft_putnbr(s / 10);
		ft_putnbr(s % 10);
	}
}