/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <cpopolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:22:11 by cpopolan          #+#    #+#             */
/*   Updated: 2023/06/01 09:00:06 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//if quadrata
int	map_squarechecker(char **tab)
{
	int	i;
	int	len;

	len = ft_strlen(tab[0]);
	i = 1;
	while (tab[i] != 0)
	{
		if (len == ft_strlen(tab[i]))
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}

//checker dei bordi su prima e ultima riga e prima e ultima colonna
int	map_borders(char **tab)
{
	int	y;
	int	x;
	int	len;

	len = ft_strlen(tab[0]);
	y = 0;
	while (tab[y])
	{
		if (tab[y][0] != '1' || tab[y][len - 1] != '1')
			return (0);
		y++;
	}
	x = 0;
	while (tab[0][x])
	{
		if (tab[0][x] != '1' || tab[y - 1][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

//checker degli elementi
//che gli vengono passati singolarmente dalla "map_checker"
int	map_elementchecker(char **tab, char elem)
{
	int	count;
	int	x;
	int	y;

	y = 0;
	count = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] == elem)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	map_call_checks(char **tab)
{
	if (!map_squarechecker(tab))
		return (0);
	if (!map_borders(tab))
		return (0);
	if (map_elementchecker(tab, 'P') != 1)
		return (0);
	if (map_elementchecker(tab, 'E') != 1)
		return (0);
	if (map_elementchecker(tab, 'C') < 1)
		return (0);
	if (!path_checker(tab, ft_map_size(tab), find_elem(tab, 'P')))
		return (0);
	return (1);
}

int	map_checker(char *path)
{
	int		res;
	char	**tab;
	int		len;

	res = 0;
	len = ft_strlen(path) - 4;
	if (len > 1 && !ft_strncmp(&path[len], ".ber", 4))
	{
		tab = mapper(path);
		if (tab)
		{
			res = map_call_checks(tab);
			ft_free_mat(tab);
		}
	}
	if (!res)
		ft_printf("Error!\nMap is wrong or doesn't exist!\n");
	return (res);
}
