#include "so_long.h"

int init_variables(t_game *game)
{
    find_char(game->map, 'E', &game->exit_x_position, &game->exit_y_position);
    game->collected_ones = 0;
    return (0);
}
