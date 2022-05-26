/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 17:03:01 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/26 15:59:50 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include <mlx.h>

typedef struct s_game {
	void	*img;
	int		img_height;
	int		img_lenght;
	void	*mlx;
	void	*mlx_win;
	char	**map;
	int		map_height;
	int		map_lenght;
	int		collectible;
	int		exits;
	int		player;
	int		player_x;
	int		player_y;
	int		walk;
	void	*img_player;
	void	*img_exits;
	void	*img_collectible;
	void	*img_floor;
	void	*img_wall;
}	t_game;

	// ft_parsing
int		ft_parsing(char *path, t_game *game);
	//ft_parsing_second_part
int		ft_parsing_map_rectangular(t_game *game);
int		ft_parsing_map_wall(t_game *game);
	//ft_mvt
int		ft_mvt(int key_code, t_game *game);
void	ft_put_exits(t_game *game);
	//ft_imgs
void	ft_convert_imgs(t_game *game);
void	ft_put_exits(t_game *game);
void	ft_assign_imgs(t_game *game);
void	ft_put_imgs(t_game *game, void *imgs, int i, int j);
	//ft_get_map
char	*ft_getmap_norm(int fd);
char	*ft_getmap(char *path);
	//ft_exits
int		ft_exit(t_game *game);
void	ft_free_map(t_game *game);

#endif