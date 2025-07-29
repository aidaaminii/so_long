#include "so_long.h"

void graphic_error(char *msg, t_game *game)
{
    ft_putstr_fd(msg, 2);
    if (game->mlx)
        mlx_terminate(game->mlx);
    exit(EXIT_FAILURE);
}

void init_game_tx(t_game *game)
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
    if (!game->wall_tx || !game->floor_tx || !game->player_tx || !game->collectible_tx || !game->exit_tx)
        graphic_error("Error\nTexture loading failed\n", game);
}

void init_game_pics(t_game *game)
{
    int ret;

    game->wall_pic = mlx_texture_to_image(game->mlx, game->wall_tx);
    game->floor_pic = mlx_texture_to_image(game->mlx, game->floor_tx);
    game->player_pic = mlx_texture_to_image(game->mlx, game->player_tx);
    game->collectible_pic = mlx_texture_to_image(game->mlx, game->collectible_tx);
    game->exit_pic = mlx_texture_to_image(game->mlx, game->exit_tx);
    if (!game->wall_pic || !game->floor_pic || !game->player_pic || !game->collectible_pic || !game->exit_pic)
        graphic_error("Error: Image creation failed\n", game);
    ret = mlx_image_to_window(game->mlx, game->player_pic,
                              game->x_position * TILE_SIZE, game->y_position * TILE_SIZE);
    if (ret < 0)
        graphic_error("Error: Could not place player image\n", game);
}

void rendering_map_wall(t_game *game)
{
    int x;
    int y;

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

void rendering_map_floor(t_game *game)
{
    int x;
    int y;

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

void rendering_map_player(t_game *game)
{
    int x;
    int y;

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

void rendering_map_collectible(t_game *game)
{
    int x;
    int y;

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

void rendering_map_exit(t_game *game)
{
    int x;
    int y;

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

void render_map(t_game *game)
{
    rendering_map_floor(game);
    rendering_map_wall(game);
    rendering_map_player(game);
    rendering_map_collectible(game);
    rendering_map_exit(game);
}

void update_display(t_game *game)
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