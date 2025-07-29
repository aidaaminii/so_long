/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_accessibility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azibaei <azibaei@student.42.fr>          +#+  +:+       +#+          */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 00:00:00 by azibaei           #+#    #+#             */
/*   Updated: 2025/07/29 00:00:00 by azibaei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**reproduce_map(t_map *map)
{
	char	**copy;
	int		i;

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

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	find_char(t_map *map, char c, int *x, int *y)
{
	int	i;
	int	j;

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

static int	dfs_path(char **map, t_point current, t_point exit)
{
	if (current.x < 0 || current.y < 0 || !map[current.y]
		|| !map[current.y][current.x] || map[current.y][current.x] == '1'
		|| map[current.y][current.x] == 'V')
		return (0);
	if (current.x == exit.x && current.y == exit.y)
		return (1);
	map[current.y][current.x] = 'V';
	return (dfs_path(map, (t_point){current.x + 1, current.y}, exit)
		|| dfs_path(map, (t_point){current.x - 1, current.y}, exit)
		|| dfs_path(map, (t_point){current.x, current.y + 1}, exit)
		|| dfs_path(map, (t_point){current.x, current.y - 1}, exit));
}

int	check_path_to_exit(t_map *map)
{
	t_point	player;
	t_point	exit;
	char	**copy_map;
	int		result;

	copy_map = reproduce_map(map);
	if (!copy_map)
		return (ft_putstr_fd("Error\nMemory allocation failed\n", 2), 1);
	if (!find_char(map, 'P', &player.x, &player.y)
		|| !find_char(map, 'E', &exit.x, &exit.y))
		return (free_map(copy_map),
			ft_putstr_fd("Error: missing P or E\n", 2), 1);
	result = dfs_path(copy_map, player, exit);
	free_map(copy_map);
	if (!result)
		ft_putstr_fd("Error\nInvalid map: No path from P to E\n", 2);
	return (!result);
}
