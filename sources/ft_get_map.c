/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 17:39:36 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/05/21 18:04:43 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_getmap_norm(int fd)
{
	char	*entirestr;
	char	*tmp;
	char	*str;

	str = get_next_line(fd);
	if (!str)
		return (NULL);
	entirestr = ft_strdup("\0");
	if (!entirestr)
	{
		free(str);
		return (NULL);
	}
	while (str)
	{
		tmp = entirestr;
		entirestr = ft_strjoin(entirestr, str);
		if (!entirestr)
			return (NULL);
		free (tmp);
		free (str);
		str = get_next_line(fd);
	}
	return (entirestr);
}

char	*ft_getmap(char *path)
{
	char			*map;
	int				fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = ft_getmap_norm(fd);
	close(fd);
	return (map);
}
