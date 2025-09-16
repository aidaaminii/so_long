/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>          +#+  +:+       +#+            */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 00:00:00 by aamini           #+#    #+#              */
/*   Updated: 2025/07/29 00:00:00 by aamini          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *content)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (content[i])
	{
		if (content[i] == '\n')
			count++;
		i++;
	}
	return (count + 1);
}

char	**allocate_area(int height)
{
	char	**area;

	area = malloc((height + 1) * sizeof(char *));
	if (!area)
		ft_putstr_fd("Error: Memory allocation failed for area\n", 2);
	return (area);
}

int	get_line_length(char *content, int index)
{
	int	len;

	if (!content)
	{
		ft_putstr_fd("Error\nContent is empty\n", 2);
		return (-1);
	}
	len = 0;
	while (content[index + len] && content[index + len] != '\n')
	{
		len++;
		if (len > MAX_LINE_LENGTH)
		{
			ft_putstr_fd("Error\nLine too long\n", 2);
			return (-1);
		}
	}
	return (len);
}

t_map	*load_map_from_file(char *filename)
{
	int				fd;
	int				height;
	t_map			*map;
	char			*file_content;
	t_asset_count	counts;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("Error\nCould not open map file\n", 2), NULL);
	file_content = read_file_content(fd);
	close(fd);
	if (!file_content)
		return (NULL);
	height = count_lines(file_content);
	map = convert_to_map(file_content, height);
	counts.collectibles = 0;
	counts.exits = 0;
	counts.players = 0;
	counts.unknowns = 0;
	set_map_assets(map, &counts);
	map->total_players = counts.players;
	map->total_collectibles = counts.collectibles;
	map->total_exits = counts.exits;
	map->total_unknowns = counts.unknowns;
	return (free(file_content), map);
}

char	*read_file_content(int fd)
{
	char	buffer[MAX_BUFFER_SIZE];
	char	*file_content;
	int		bytes_read;
	size_t	total_size;

	file_content = NULL;
	total_size = 0;
	bytes_read = read(fd, buffer, MAX_BUFFER_SIZE - 1);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		file_content = resize_content(file_content, total_size,
				bytes_read, buffer);
		if (!file_content)
			return (NULL);
		total_size += bytes_read;
		bytes_read = read(fd, buffer, MAX_BUFFER_SIZE - 1);
	}
	return (file_content);
}
