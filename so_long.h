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

typedef struct s_map
{
	char **area;
	int width;
	int height;
} t_map;

typedef struct s_game
{
	t_map *map;
	mlx_t *mlx;
} t_game;

int check_map_filename(char *filename);
t_map *load_map_from_file(char *filename);

#endif
