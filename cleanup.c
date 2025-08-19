/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>          +#+  +:+       +#+            */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 00:00:00 by aamini           #+#    #+#              */
/*   Updated: 2025/08/19 00:00:00 by aamini          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->area)
	{
		i = 0;
		while (i < map->height && map->area[i])
		{
			free(map->area[i]);
			i++;
		}
		free(map->area);
	}
	free(map);
}

void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
	if (game->map)
		free_map(game->map);
	if (game->mlx)
		mlx_terminate(game->mlx);
}
