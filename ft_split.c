/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:44:44 by mjarboua          #+#    #+#             */
/*   Updated: 2022/12/10 20:58:44 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) == 0 || len <= 0)
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (j < len && s[start])
	{
		str[j++] = s[start++];
	}
	str[j] = '\0';
	return (str);
}

static size_t	w_counter(char *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i] != '\0')
			counter++;
		while (s[i] != c && s[i])
			i++;
	}
	return (counter);
}

static char	**free_all(char **str, int c)
{
	if (!str)
	{
		while (0 <= c)
		{
			c--;
			free (str[c]);
			str[c] = 0;
		}
		free (str);
		str = 0;
	}
	return (NULL);
}

static char	**allocate(char **str, char *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	while (i < w_counter((char *)s, c))
	{
		while (s[start] == c && s[start] != '\0')
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		str[i] = ft_substr((char *)s, start, end - start);
		if (!str[i])
			return (free_all(str, i));
		i++;
		start = end;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char *s, char c)
{
	char	**str;

	if (!s)
		return (0);
	str = (char **)malloc((w_counter((char *)s, c) + 1) * sizeof(char *));
	if (!str)
		return (0);
	str = allocate(str, (char *)s, c);
	return (str);
}
