/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:18:31 by cpopolan          #+#    #+#             */
/*   Updated: 2023/01/18 16:06:06 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_search(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*join(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1)
		s1 = ft_calloc(sizeof (char), 1);
	res = ft_calloc(sizeof(char), (ft_len(s1) + ft_len(s2) + 1));
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	return (res);
}

char	*line_before(char *s, int i)
{
	char	*res;
	int		j;

	j = 0;
	res = ft_calloc(sizeof(char), (i + 1));
	while (j < i)
	{
		res[j] = s[j];
		j++;
	}
	return (res);
}

char	*line_after(char *s, int i)
{
	char	*res;
	int		j;

	if (ft_len(s) - i == 0)
	{
		free(s);
		return (0);
	}
	j = 0;
	res = ft_calloc(sizeof(char), (ft_len(s) - i + 1));
	while (s[i])
	{
		res[j] = s[i];
		j++;
		i++;
	}
	free(s);
	return (res);
}
