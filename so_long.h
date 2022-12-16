/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:18:28 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/13 19:22:27 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 5

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct l_mlx
{
	char			**arr;
	char			*str;
	void			*mlx;
	void			*win;
	void			*img;
	int				x;
	int				y;
	int				p_i;
	int				p_j;
	int				coins;
	int				j;
	int				i;
	int				row;
	int				columns;
	int				width;
	int				height;
}				t_mlx;


char	**ft_split(char *str, char c);
char	*ft_substr(char *str, unsigned int start, unsigned int len);
char	*ft_strdup(char *str);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);

// the folowing functions are made to check the map 

int		check_map(t_mlx *v);
int		check_len(char **v);
int		check_wall(char **v);
int		check_p_e(t_mlx *v);
int		check_f_l(char **v);
// int		check_coins(t_mlx *v);

// outputting functions

void	ft_putnbr(int nbr);
void	ft_putchar(char c);
void	ft_putstr(char *str);

// drawing functions 

int		draw_map(t_mlx *v);
void	draw_up(t_mlx *v);
void	draw_down(t_mlx *v);
void	draw_left(t_mlx *v);
void	draw_right(t_mlx *v);
int		check_key_and_print(int key, void *param);

// to check path
char	ft_get_pos(char **t, int x, int y);
int		ft_search_char(char **t, int x, int y, char n);

#endif
