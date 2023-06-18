/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpopolan <cpopolan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 15:36:23 by cpopolan          #+#    #+#             */
/*   Updated: 2023/06/01 09:08:24 by cpopolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# define ESC 65307

typedef struct s_vector {
	int	x;
	int	y;
}				t_vector;

typedef struct s_image {
	void		*img;
	t_vector	size;
}				t_image;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	char		**map;
	t_vector	map_size;
	t_image		player;
	t_image		floor;
	t_image		wall;
	t_image		exit;
	t_image		coll;
	int			coll_n;
	int			mov_n;
	t_vector	coor;

}				t_vars;

char		**mapper(char *path);
void		ft_print_map(t_vars *main);
int			map_checker(char *path);
int			map_elementchecker(char **tab, char elem);
int			path_checker(char **tab, t_vector size, t_vector begin);
t_vector	ft_map_size(char **tab);
t_vector	find_elem(char **tab, char elem);
int			key_hook(int keycode, t_vars *main);
int			ft_close(t_vars *main);
void		ft_free_mat(char **tab);

#endif
