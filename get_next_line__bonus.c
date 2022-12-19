/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line__bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:23:46 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/18 21:14:12 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long__bonus.h"

int	check_coins(char **str)
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

char	*print_them_lines(char *save)
{
	int		i;
	char	*s;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i])
		i++;
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	i = -1;
	while (save[++i])
		s[i] = save[i];
	s[i] = '\0';
	return (s);
}

char	*read_file(int fd, char *save)
{
	char	*buff;
	int		read_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(save);
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*saved;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	saved = read_file(fd, saved);
	if (!saved)
		return (NULL);
	ret = print_them_lines(saved);
	return (ret);
}
