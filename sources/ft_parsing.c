/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:47:47 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/21 15:51:34 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_parsing_map_elements_minimum(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (game->map[j])
	{
		i = 0;
		while (game->map[j][i])
		{
			if (game->map[j][i] == 'C')
				game->collectible += 1;
			if (game->map[j][i] == 'E')
				game->exits += 1;
			if (game->map[j][i] == 'P')
				game->player += 1;
			i++;
		}
		j++;
	}
	if (game->collectible < 1 || game->exits < 1 || game->player != 1)
	{
		ft_printf("Error : bad number of elements\n");
		return (-1);
	}
	return (0);
}

int	ft_parsing_map_elements(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] != '0' && game->map[y][x] != '1'
				&& game->map[y][x] != 'C' && game->map[y][x] != 'E'
				&& game->map[y][x] != 'P')
			{
				ft_printf("Error : bad elements\n");
				return (-1);
			}
			x++;
		}
		y++;
	}
	game->map_height = y;
	game->map_lenght = x;
	return (0);
}

int	ft_parsing_map_name(char *path)
{
	int	i;

	i = 0;
	while (path[i])
		i++;
	if (i < 5 && path[i] != 'r' && path[i - 1] != 'e' && \
		path[i - 2] != 'b' && path[i - 3] != '.')
	{
		ft_printf("Error : bad map extension or name\n");
		return (-1);
	}
	return (0);
}

int	ft_parsing(char *path, t_game *game)
{
	game->collectible = 0;
	game->exits = 0;
	game->player = 0;
	if (ft_parsing_map_name(path) == -1)
		return (-1);
	if (ft_parsing_map_elements(game) == -1)
		return (-1);
	if (ft_parsing_map_elements_minimum(game) == -1)
		return (-1);
	if (ft_parsing_map_rectangular(game) == -1)
		return (-1);
	if (ft_parsing_map_wall(game) == -1)
		return (-1);
	return (0);
}
