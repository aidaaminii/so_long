/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>          +#+  +:+       +#+            */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 00:00:00 by aamini           #+#    #+#              */
/*   Updated: 2025/07/29 00:00:00 by aamini          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	initialize_game(char *filename, t_game *game)
{
	game->map = NULL;
	game->mlx = NULL;
	if (check_map_filename(filename) != 0)
		return (ft_putstr_fd("Error\nInvalid map filename.\n", 2), 1);
	game->map = load_map_from_file(filename);
	if (!game->map || validate_map(game->map) != 0)
	{
		if (game->map)
			free_map(game->map);
		return (1);
	}
	start_position(game);
	init_variables(game);
	init_game_tx(game);
	init_game_pics(game);
	render_map(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;
	int		result;

	if (argc != 2)
		return (ft_putstr_fd("Error\nUsage is: ./so_long map.ber\n", 2), 1);
	result = initialize_game(argv[1], &game);
	if (result != 0)
		return (ft_putstr_fd("Error\nUsage is: ./so_long map.ber\n", 2), 1);
	mlx_key_hook(game.mlx, handle_input, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
}
