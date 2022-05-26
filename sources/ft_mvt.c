/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mvt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:37:37 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/26 16:26:33 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_mvts(t_game *game, int y, int x)
{
	if (game->map[y][x] != '1')
	{
		if (game->map[y][x] == 'C')
		{
			ft_put_imgs(game, game->img_floor, x, y);
			game->collectible -= 1;
			game->map[y][x] = '0';
		}
		game->walk += 1;
		ft_printf("%d\n", game->walk);
		if (game->collectible == 0 && game->map[y][x] == 'E')
			ft_exit(game);
		ft_put_imgs(game, game->img_floor, game->player_x, game->player_y);
		ft_put_imgs(game, game->img_player, x, y);
		game->player_y = y;
		game->player_x = x;
	}
}

int	ft_mvt(int key_code, t_game *game)
{
	if (key_code == 13)
		ft_mvts(game, game->player_y - 1, game->player_x);
	if (key_code == 0)
		ft_mvts(game, game->player_y, game->player_x - 1);
	if (key_code == 1)
		ft_mvts(game, game->player_y + 1, game->player_x);
	if (key_code == 2)
		ft_mvts(game, game->player_y, game->player_x + 1);
	if (key_code == 53)
		ft_exit(game);
	if (game->collectible == 0)
		ft_put_exits(game);
	return (0);
}
