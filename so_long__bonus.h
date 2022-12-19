/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long__bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:18:28 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/18 21:12:18 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG__BONUS_H
# define SO_LONG__BONUS_H

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

// outputting functions

void	ft_putnbr(int nbr);
void	ft_putchar(char c);
void	ft_putstr(char *str);

// drawing functions 

int		draw_map(t_mlx *v);
void	draw_up(t_mlx *v, int *moves);
void	draw_down(t_mlx *v, int *moves);
void	draw_left(t_mlx *v, int *moves);
void	draw_right(t_mlx *v, int *moves);
int		check_key_and_print(int key, void *param);

// to check path
int		get_player_pos(char **str, int *x, int *y);

// helping func
int		get_arr_len(char **str);
char	**allocate_clone(char **v);
int		check_coins(char **str);
void	free_arr(char **str);

// backtracking func
int		back_tracking(t_mlx *v);

#endif
