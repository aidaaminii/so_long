/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>          +#+  +:+       +#+            */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 00:00:00 by aamini           #+#    #+#              */
/*   Updated: 2025/07/29 00:00:00 by aamini          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*resize_content(char *content, size_t total_size,
			size_t bytes_read, char *buffer)
{
	char	*new_content;

	new_content = malloc(total_size + bytes_read + 1);
	if (!new_content)
	{
		free(content);
		return (NULL);
	}
	if (content)
	{
		ft_memcpy(new_content, content, total_size);
		free(content);
	}
	ft_memcpy(new_content + total_size, buffer, bytes_read + 1);
	return (new_content);
}

char	*extract_line(char *content, int *index)
{
	int		len;
	char	*line;
	int		i;

	len = get_line_length(content, *index);
	if (len == -1)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = content[*index + i];
		i++;
	}
	line[len] = '\0';
	*index += len;
	if (content[*index] == '\n')
		(*index)++;
	return (line);
}

t_map	*convert_to_map(char *file_content, int height)
{
	char	**area;
	t_map	*map;
	int		i;
	int		index;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	area = allocate_area(height);
	if (!area)
		return (free(map), NULL);
	i = 0;
	index = 0;
	while (i < height)
	{
		area[i] = extract_line(file_content, &index);
		if (!area[i])
			return (free_partial_map(area, i, map));
		i++;
	}
	area[height] = NULL;
	map->height = height;
	map->width = ft_strlen(area[0]);
	map->area = area;
	return (map);
}

void	set_map_assets(t_map *map, t_asset_count *counts)
{
	int	i;
	int	j;

	i = 0;
	while (map->area[i])
	{
		j = 0;
		while (map->area[i][j])
		{
			if (map->area[i][j] == 'P')
				(counts->players)++;
			else if (map->area[i][j] == 'C')
				(counts->collectibles)++;
			else if (map->area[i][j] == 'E')
				(counts->exits)++;
			else if (map->area[i][j] != '1' && map->area[i][j] != '0')
				(counts->unknowns)++;
			j++;
		}
		i++;
	}
}

t_map	*free_partial_map(char **area, int index, t_map *map)
{
	ft_putstr_fd("Error\nMemory allocation failed\n", 2);
	while (index > 0)
		free(area[--index]);
	free(area);
	free(map);
	return (NULL);
}
