#include "so_long.h"

void start_position(t_game *game)
{
    int y;
    int x;
    find_char(game->map, 'P', &x, &y);
    game->x_position = x;
    game->y_position = y;
}

int is_valid_move(t_game *game, int new_x, int new_y)
{
    if (new_x < 0 || new_y < 0 || new_x >= game->map->width || new_y >= game->map->height)
        return (0);
    if (game->map->area[new_y][new_x] == '1')
    {
        ft_putstr_fd("!You hit the wall!\n", 2);
        return (0);
    }
    return (1);
}

void handle_collectible(t_game *game, int new_x, int new_y)
{
    if (game->map->area[new_y][new_x] == 'C')
    {
        game->collected_ones++;
        game->map->area[new_y][new_x] = '0';
        render_map(game);
    }
}

void move(t_game *game, int delta_x, int delta_y)
{
    int new_x;
    int new_y;

    new_x = game->x_position + delta_x;
    new_y = game->y_position + delta_y;
    if (!is_valid_move(game, new_x, new_y))
        return;
    handle_collectible(game, new_x, new_y);
    game->x_position = new_x;
    game->y_position = new_y;
    update_display(game);
    int reached = game->x_position == game->exit_x_position && game->y_position == game->exit_y_position;
    if (reached && game->collected_ones == game->map->total_collectibles)
    {
        ft_putstr_fd("Game Finished!Good job!!\n", 1);
        mlx_close_window(game->mlx);
        return;
    }
}

void handle_input(mlx_key_data_t keydata, void *param)
{
    t_game *game;

    game = (t_game *)param;
    if (keydata.action != MLX_PRESS && keydata.action != MLX_REPEAT)
        return;
    if (keydata.key == MLX_KEY_ESCAPE)
        mlx_close_window(game->mlx);
    else if (keydata.key == MLX_KEY_W)
        move(game, 0, -1);
    else if (keydata.key == MLX_KEY_S)
        move(game, 0, 1);
    else if (keydata.key == MLX_KEY_A)
        move(game, -1, 0);
    else if (keydata.key == MLX_KEY_D)
        move(game, 1, 0);
}
