/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 16:41:58 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/26 16:23:57 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_main_norm_if_no_line_map(void)
{
	ft_printf("Error 1: bad map path\n");
	return (0);
}

void	ft_main(t_game *game)
{
	game->mlx_win = mlx_new_window(game->mlx, game->map_lenght * 64, \
		game->map_height * 64, \
		"Le meilleur jeu d'amour de tous les temps");
	ft_convert_imgs(game);
	ft_assign_imgs(game);
	mlx_key_hook(game->mlx_win, ft_mvt, game);
	mlx_hook(game->mlx_win, 17, 1 << 0, ft_exit, game);
	mlx_loop(game->mlx);
}

int	ft_argc(int argc)
{
	if (argc != 2)
	{
		ft_printf("Error : wrong number of arguments");
		return (-1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	game;
	char	*line_map;

	if (ft_argc(argc) == -1)
		return (0);
	game.walk = 0;
	line_map = ft_getmap(argv[1]);
	if (!line_map)
		return (ft_main_norm_if_no_line_map());
	game.map = ft_split(line_map, '\n');
	free(line_map);
	if (!game.map)
	{
		ft_printf("Error : bad map path\n");
		return (0);
	}
	if (ft_parsing(argv[1], &game) == -1)
	{
		ft_free_map(&game);
		return (0);
	}
	game.mlx = mlx_init();
	ft_main(&game);
	return (0);
}
