/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:06:13 by aamini            #+#    #+#             */
/*   Updated: 2025/07/24 17:14:32 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft/libft.h"
#include "MLX42/include/MLX42/MLX42.h"

#define TILE_SIZE 64
#define MAX_LINE_LENGTH 1024
#define MAX_BUFFER_SIZE 1024
#define MAX_SCREEN_WIDTH 1920
#define MAX_SCREEN_HEIGHT 1080

typedef struct s_map
{
	char **area;
	int width;
	int height;

	int total_players;
	int total_exits;
	int total_collectibles;
	int total_unknowns;
} t_map;

typedef struct s_game
{
	t_map *map;
	mlx_t *mlx;
	mlx_texture_t *wall_tx;
	mlx_texture_t *floor_tx;
	mlx_texture_t *player_tx;
	mlx_texture_t *exit_tx;
	mlx_texture_t *collectible_tx;
	mlx_image_t *wall_pic;
	mlx_image_t *floor_pic;
	mlx_image_t *player_pic;
	mlx_image_t *exit_pic;
	mlx_image_t *collectible_pic;

	int x_position;
	int y_position;
	int exit_x_position;
	int exit_y_position;
	int collected_ones;
} t_game;

int check_map_filename(char *filename);
t_map *load_map_from_file(char *filename);
int validate_map(t_map *map);
int check_path_to_exit(t_map *map);
int find_char(t_map *map, char c, int *x, int *y);
void start_position(t_game *game);
int init_variables(t_game *game);
void init_game_tx(t_game *game);
void init_game_pics(t_game *game);
void render_map(t_game *game);
void handle_input(mlx_key_data_t keydata, void *param);
void update_display(t_game *game);
void set_map_assets(t_map *map, int *players, int *collectibles, int *exits, int *unknowns);

#endif
