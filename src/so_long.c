/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <cpopolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:52:33 by cpopolan          #+#    #+#             */
/*   Updated: 2023/06/13 15:56:12 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_close(t_vars *main)
{
	ft_free_mat(main->map);
	mlx_destroy_image(main->mlx, main->player.img);
	mlx_destroy_image(main->mlx, main->exit.img);
	mlx_destroy_image(main->mlx, main->coll.img);
	mlx_destroy_image(main->mlx, main->wall.img);
	mlx_destroy_image(main->mlx, main->floor.img);
	mlx_destroy_window(main->mlx, main->win);
	mlx_destroy_display(main->mlx);
	free(main->mlx);
	exit(0);
}

// declaring images here
void	ft_imager(t_vars *main)
{
	main->player.img = mlx_xpm_file_to_image(main->mlx, \
		"textures/player.xpm", &main->player.size.x, &main->player.size.y);
	main->floor.img = mlx_xpm_file_to_image(main->mlx, \
		"textures/floor.xpm", &main->floor.size.x, &main->floor.size.y);
	main->wall.img = mlx_xpm_file_to_image(main->mlx, \
		"textures/wall.xpm", &main->wall.size.x, &main->wall.size.y);
	main->exit.img = mlx_xpm_file_to_image(main->mlx, \
		"textures/exit.xpm", &main->exit.size.x, &main->exit.size.y);
	main->coll.img = mlx_xpm_file_to_image(main->mlx, \
		"textures/coll.xpm", &main->coll.size.x, &main->coll.size.y);
}

int	main(int ac, char **av)
{
	t_vars	main;

	if (!map_checker(av[1]))
		return (0);
	main.map = mapper(av[1]);
	main.map_size = ft_map_size(main.map);
	main.mlx = mlx_init();
	ft_imager(&main);
	main.win = mlx_new_window(main.mlx, main.map_size.x * main.player.size.x, \
		main.map_size.y * main.player.size.y, "so_long");
	main.coor = find_elem(main.map, 'P');
	main.coll_n = map_elementchecker(main.map, 'C');
	main.mov_n = 0;
	ft_print_map(&main);
	mlx_hook(main.win, 17, 0, ft_close, &main);
	mlx_hook(main.win, 2, 1L << 0, key_hook, &main);
	mlx_loop(main.mlx);
}
