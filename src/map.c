/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <cpopolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:42:09 by cpopolan          #+#    #+#             */
/*   Updated: 2023/03/30 11:10:30 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_join(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (res);
}

char	**mapper(char *path)
{
	int		fd;
	char	*line;
	char	*all;
	char	**map;

	if (path)
	{
		fd = open(path, O_RDONLY);
		if (fd != -1)
		{	
			all = ft_calloc(1, 1);
			while (1)
			{
				line = get_next_line(fd);
				if (!line)
					break ;
				all = ft_join(all, line);
			}
			map = ft_split(all, '\n');
			free(all);
			close(fd);
			return (map);
		}
	}
	return (0);
}

void	ft_print_img(t_vars *main, t_image image, int x, int y)
{
	mlx_put_image_to_window(main->mlx, main->win, \
		image.img, x * image.size.x, y * image.size.y);
}

void	ft_print_map(t_vars *main)
{
	int	x;
	int	y;

	y = 0;
	while (main->map[y])
	{
		x = 0;
		while (main->map[y][x])
		{
			if (main->map[y][x] == 'P')
				ft_print_img(main, main->player, x, y);
			else if (main->map[y][x] == 'E')
				ft_print_img(main, main->exit, x, y);
			else if (main->map[y][x] == 'C')
				ft_print_img(main, main->coll, x, y);
			else if (main->map[y][x] == '1')
				ft_print_img(main, main->wall, x, y);
			else if (main->map[y][x] == '0')
				ft_print_img(main, main->floor, x, y);
			x++;
		}
		y++;
	}
}
