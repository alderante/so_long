/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <cpopolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:48:24 by cpopolan          #+#    #+#             */
/*   Updated: 2023/03/30 11:18:55 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//line[25] trasformo in '0' il coll ottenuto
//		per evitare di ottenerlo piu' volte
void	movement(t_vars *main, int y, int x)
{
	if (main->map[y][x] == '1' || (main->map[y][x] == 'E' && main->coll_n > 0))
		return ;
	else if (main->map[y][x] == 'C')
		main->coll_n--;
	else if (main->map[y][x] == 'E' && main->coll_n == 0)
		ft_close(main);
	main->map[y][x] = '0';
	mlx_put_image_to_window(main->mlx, main->win, main->floor.img, \
		main->coor.x * main->floor.size.x, main->coor.y * main->floor.size.y);
	main->coor.y = y;
	main->coor.x = x;
	mlx_put_image_to_window(main->mlx, main->win, main->player.img, \
		main->coor.x * main->player.size.x, main->coor.y * main->player.size.y);
	main->mov_n++;
	ft_printf("\rNumber of movements is %d", main->mov_n);
}

// movimento del personaggio
int	key_hook(int keycode, t_vars *main)
{
	if (keycode == ESC)
		ft_close(main);
	else if (keycode == 'w' || keycode == 65362)
		movement(main, main->coor.y - 1, main->coor.x);
	else if (keycode == 'a' || keycode == 65361)
		movement(main, main->coor.y, main->coor.x - 1);
	else if (keycode == 'd' || keycode == 65363)
		movement(main, main->coor.y, main->coor.x + 1);
	else if (keycode == 's' || keycode == 65364)
		movement(main, main->coor.y + 1, main->coor.x);
	return (0);
}
