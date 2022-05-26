/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_second_part.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:43:21 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/19 14:49:15 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_parsing_map_wall(t_game *game)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (game->map[j])
	{
		while (game->map[j][i])
		{
			if (game->map[0][i] != '1'
			|| game->map[game->map_height - 1][i] != '1')
			{
				ft_printf("Error : bad wall\n");
				return (-1);
			}
			i++;
		}
		if (game->map[j][0] != '1' || game->map[j][game->map_lenght - 1] != '1')
		{
			ft_printf("Error : bad wall\n");
			return (-1);
		}
		j++;
	}
	return (0);
}

int	ft_parsing_map_rectangular(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			j++;
		}
		if (j != game->map_lenght)
		{
			ft_printf("Error : map not rectangular\n");
			return (-1);
		}
		i++;
	}
	return (0);
}
