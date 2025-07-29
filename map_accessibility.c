#include "so_long.h"

char **reproduce_map(t_map *map)
{
	char **copy;
	int i;

	copy = malloc((map->height + 1) * sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < map->height)
	{
		copy[i] = ft_strdup(map->area[i]);
		if (!copy[i])
		{
			while (i > 0)
				free(copy[--i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[map->height] = NULL;
	return (copy);
}

void free_map(char **map)
{
	int i = 0;

	if (!map)
		return;
	while (map[i])
		free(map[i++]);
	free(map);
}

int find_char(t_map *map, char c, int *x, int *y)
{
	int i;
	int j;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width && map->area[i][j])
		{
			if (map->area[i][j] == c)
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int dfs_path(char **map, int x, int y, int ex, int ey)
{
	if (x < 0 || y < 0 || !map[y] || !map[y][x] || map[y][x] == '1'
		|| map[y][x] == 'V')
		return (0);
	if (x == ex && y == ey)
		return (1);
	map[y][x] = 'V';
	return (dfs_path(map, x + 1, y, ex, ey) || dfs_path(map, x - 1, y, ex, ey)
		|| dfs_path(map, x, y + 1, ex, ey) || dfs_path(map, x, y - 1, ex, ey));
}

int check_path_to_exit(t_map *map)
{
	int px, py, ex, ey;
	char **copy_map;
	int result;

	copy_map = reproduce_map(map);
	if (!copy_map)
		return (ft_putstr_fd("Error\nMemory allocation failed\n", 2), 1);
	if (!find_char(map, 'P', &px, &py) || !find_char(map, 'E', &ex, &ey))
		return (free_map(copy_map), ft_putstr_fd("Error: missing P or E\n", 2), 1);
	result = dfs_path(copy_map, px, py, ex, ey);
	free_map(copy_map);
	if (!result)
		ft_putstr_fd("Error\nInvalid map: No path from P to E\n", 2);
	return (!result);
}
