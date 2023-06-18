/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <cpopolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 10:54:33 by cpopolan          #+#    #+#             */
/*   Updated: 2023/03/30 11:32:38 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//libero matrice, stringa per stringa
void	ft_free_mat(char **tab)
{
	int	y;

	if (tab)
	{
		y = 0;
		while (tab[y])
		{
			free(tab[y]);
			y++;
		}
		free(tab);
	}
}

//da qui prendo le coordinate di qualunque cosa
t_vector	find_elem(char **tab, char elem)
{
	t_vector	coor;

	coor.y = 0;
	while (tab[coor.y])
	{
		coor.x = 0;
		while (tab[coor.y][coor.x])
		{
			if (tab[coor.y][coor.x] == elem)
				return (coor);
			coor.x++;
		}
		coor.y++;
	}
	return ((t_vector){-1, -1});
}

//per sapere le dimensioni della mappa
t_vector	ft_map_size(char **tab)
{
	t_vector	size;

	size.x = ft_strlen(tab[0]);
	size.y = 0;
	while (tab[size.y])
		size.y++;
	return (size);
}

// floodfill (controllo path)-----------------
void	fill(char **tab, t_vector size, t_vector cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| tab[cur.y][cur.x] == '1')
		return ;
	if (tab[cur.y][cur.x] == 'E')
	{
		tab[cur.y][cur.x] = '1';
		return ;
	}
	tab[cur.y][cur.x] = '1';
	fill(tab, size, (t_vector){cur.x - 1, cur.y});
	fill(tab, size, (t_vector){cur.x + 1, cur.y});
	fill(tab, size, (t_vector){cur.x, cur.y - 1});
	fill(tab, size, (t_vector){cur.x, cur.y + 1});
}

int	path_checker(char **tab, t_vector size, t_vector begin)
{
	int	x;
	int	y;

	fill(tab, size, begin);
	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (tab[y][x] != '0' && tab[y][x] != '1')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
// fine floodfill (controllo path)-------------