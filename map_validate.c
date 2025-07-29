#include "so_long.h"

int check_map_filename(char *filename)
{
  int len;

  len = ft_strlen(filename);
  if (len < 5)
    return (1);
  if (ft_strncmp(filename + len - 4, ".ber", 4) != 0)
    return (1);
  return (0);
}

int validate_walls(t_map *map)
{
  int i;
  i = 0;

  while (i < map->width)
  {
    if (map->area[0][i] != '1' || map->area[map->height - 1][i] != '1')
      return (1);
    i++;
  }

  i = 0;
  while (i < map->height)
  {
    if (map->area[i][0] != '1' || map->area[i][map->width - 1] != '1')
      return (1);
    i++;
  }
  return (0);
}

int validate_characters(t_map *map)
{
  if (map->total_unknowns > 0)
    return (ft_putstr_fd("Error\nInvalid char in the map file\n", 2), 1);
  if (map->total_players != 1)
    return (ft_putstr_fd("Error\nMore than one player\n", 2), 1);
  if (map->total_exits != 1)
    return (ft_putstr_fd("Error\nMore than one exit\n", 2), 1);
  if (map->total_collectibles == 0)
    return (ft_putstr_fd("Error\nMust contain at least 1 collectible\n", 2), 1);
  return (0);
}

int check_window_size(t_map *map)
{
  int window_width;
  int window_height;

  window_width = map->width * TILE_SIZE;
  window_height = map->height * TILE_SIZE;
  if (window_width > MAX_SCREEN_WIDTH || window_height > MAX_SCREEN_HEIGHT)
  {
    ft_putstr_fd("Error\nMap size exceeds screen dimensions!\n", 2);
    return (1);
  }
  return (0);
}

int validate_map(t_map *map)
{
  int i;
  int width;

  i = 0;
  width = map->width;
  while (i < map->height)
  {
    int tmp;
    char *trimmed = ft_strtrim(map->area[i], "\n\r");
    tmp = ft_strlen(trimmed);
    free(trimmed);
    if (tmp != width)
    {
      ft_putstr_fd("Error\nInvalid map, check each rows.\n", 2);
      return (1);
    }
    i++;
  }

  return (validate_walls(map) || validate_characters(map) || check_window_size(map) || check_path_to_exit(map));
}
