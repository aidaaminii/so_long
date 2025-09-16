/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>          +#+  +:+       +#+            */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 00:00:00 by aamini           #+#    #+#              */
/*   Updated: 2025/07/29 00:00:00 by aamini          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	graphic_error(char *msg, t_game *game)
{
	ft_putstr_fd(msg, 2);
	cleanup_game(game);
	exit(EXIT_FAILURE);
}

void	init_game_tx(t_game *game)
{
	game->mlx = mlx_init(game->map->width * TILE_SIZE,
			game->map->height * TILE_SIZE, "so_long", true);
	if (!game->mlx)
		graphic_error("Error\nMLX Initialization failed\n", game);
	game->wall_tx = mlx_load_png("textures/wall.png");
	game->floor_tx = mlx_load_png("textures/floor.png");
	game->player_tx = mlx_load_png("textures/player.png");
	game->collectible_tx = mlx_load_png("textures/collectible.png");
	game->exit_tx = mlx_load_png("textures/exit.png");
	if (!game->wall_tx || !game->floor_tx || !game->player_tx
		|| !game->collectible_tx || !game->exit_tx)
		graphic_error("Error\nTexture loading failed\n", game);
}

void	init_game_pics(t_game *game)
{
	int	ret;

	game->wall_pic = mlx_texture_to_image(game->mlx, game->wall_tx);
	game->floor_pic = mlx_texture_to_image(game->mlx, game->floor_tx);
	game->player_pic = mlx_texture_to_image(game->mlx, game->player_tx);
	game->collectible_pic = mlx_texture_to_image(game->mlx,
			game->collectible_tx);
	game->exit_pic = mlx_texture_to_image(game->mlx, game->exit_tx);
	if (!game->wall_pic || !game->floor_pic || !game->player_pic
		|| !game->collectible_pic || !game->exit_pic)
		graphic_error("Error: Image creation failed\n", game);
	ret = mlx_image_to_window(game->mlx, game->player_pic,
			game->x_position * TILE_SIZE, game->y_position * TILE_SIZE);
	if (ret < 0)
		graphic_error("Error: Could not place player image\n", game);
}

void	render_map(t_game *game)
{
	int			x;
	int			y;
	mlx_image_t	*m;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			m = game->floor_pic;
			mlx_image_to_window(game->mlx, m, x * TILE_SIZE, y * TILE_SIZE);
			if (game->map->area[y][x] == 'P')
				m = game->player_pic;
			else if (game->map->area[y][x] == 'E')
				m = game->exit_pic;
			else if (game->map->area[y][x] == 'C')
				m = game->collectible_pic;
			else if (game->map->area[y][x] == '1')
				m = game->wall_pic;
			mlx_image_to_window(game->mlx, m, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

void	update_display(t_game *game)
{
	mlx_delete_image(game->mlx, game->player_pic);
	game->player_pic = mlx_texture_to_image(game->mlx, game->player_tx);
	if (!game->player_pic)
		graphic_error("Error recreating player image\n", game);
	if (mlx_image_to_window(game->mlx, game->player_pic,
			game->x_position * TILE_SIZE,
			game->y_position * TILE_SIZE) < 0)
		graphic_error("Error placing player image\n", game);
}
