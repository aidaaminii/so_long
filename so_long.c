#include "so_long.h"

void error_initiation_tx(char *msg, t_game *game)
{
    ft_putstr_fd(msg, 2);
    if (game->mlx)
		mlx_terminate(game->mlx);
    exit(EXIT_FAILURE);
}

int initialize_game(char *filename, t_game *game)
{
    if (check_map_filename(filename) != 0)
    {
        return (ft_putstr_fd("Error\nInvalid map filename.\n", 2), 1);
    }

    game->map = load_map_from_file(filename);
    game->mlx = mlx_init(game->map->width * TILE_SIZE,
                         game->map->height * TILE_SIZE, "so_long", true);
    if (!game->mlx)
        error_initiation_tx("Error\nMLX Initialization failed\n", game);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        return (ft_putstr_fd("Error\nUsage is: ./so_long map.ber\n", 2), 1);
    }

    t_game game;
    return initialize_game(argv[1], &game);
}
