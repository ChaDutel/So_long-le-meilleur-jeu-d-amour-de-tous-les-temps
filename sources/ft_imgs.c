/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imgs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:43:56 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/26 16:22:20 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_convert_imgs(t_game *game)
{
	game->img_floor = mlx_xpm_file_to_image(game->mlx, \
		"./sets/floor_<3.xpm", &game->img_lenght, &game->img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, \
		"./sets/wall_heart_broken.xpm", &game->img_lenght, &game->img_height);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx, \
		"./sets/Rose_collectible.xpm", &game->img_lenght, &game->img_height);
	game->img_player = mlx_xpm_file_to_image(game->mlx, \
		"./sets/Duck-Perei.xpm", &game->img_lenght, &game->img_height);
	game->img_exits = mlx_xpm_file_to_image(game->mlx, \
		"./sets/exit_moi.xpm", &game->img_lenght, &game->img_height);
}

void	ft_put_imgs(t_game *game, void *imgs, int i, int j)
{
	mlx_put_image_to_window \
		(game->mlx, game->mlx_win, imgs, i * 64, j * 64);
}

void	ft_put_exits(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'E')
				ft_put_imgs(game, game->img_exits, i, j);
			i++;
		}
		j++;
	}
	return ;
}

void	ft_assign_imgs(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			ft_put_imgs(game, game->img_floor, i, j);
			if (game->map[j][i] == '1')
				ft_put_imgs(game, game->img_wall, i, j);
			if (game->map[j][i] == 'C')
				ft_put_imgs(game, game->img_collectible, i, j);
			if (game->map[j][i] == 'P')
			{
				ft_put_imgs(game, game->img_player, i, j);
				game->player_x = i;
				game->player_y = j;
			}
			i++;
		}
		j++;
	}
}
