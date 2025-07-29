/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_render.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azibaei <azibaei@student.42.fr>          +#+  +:+       +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 00:00:00 by azibaei           #+#    #+#             */
/*   Updated: 2025/07/29 00:00:00 by azibaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rendering_map_wall(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->area[y][x] == '1')
				mlx_image_to_window(game->mlx, game->wall_pic,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	rendering_map_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->area[y][x] == '0')
				mlx_image_to_window(game->mlx, game->floor_pic,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	rendering_map_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->area[y][x] == 'P')
				mlx_image_to_window(game->mlx, game->player_pic,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	rendering_map_collectible(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->area[y][x] == 'C')
				mlx_image_to_window(game->mlx, game->collectible_pic,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	rendering_map_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->area[y][x] == 'E')
				mlx_image_to_window(game->mlx, game->exit_pic,
					x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
