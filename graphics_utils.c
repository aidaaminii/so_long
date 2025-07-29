/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azibaei <azibaei@student.42.fr>          +#+  +:+       +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 00:00:00 by azibaei           #+#    #+#             */
/*   Updated: 2025/07/29 00:00:00 by azibaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	rendering_map_floor_everywhere(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			mlx_image_to_window(game->mlx, game->floor_pic,
				x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
