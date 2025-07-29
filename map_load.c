#include "so_long.h"

int count_lines(char *content)
{
  int count;
  int i;

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

char **allocate_area(int height)
{
  char **area;

  area = malloc((height + 1) * sizeof(char *));
  if (!area)
    ft_putstr_fd("Error: Memory allocation failed for area\n", 2);
  return (area);
}

int get_line_length(char *content, int index)
{
  int len;

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

static char *resize_content(char *content, size_t total_size,
                            size_t bytes_read, char *buffer)
{
  char *new_content;

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

char *extract_line(char *content, int *index)
{
  int len;
  char *line;
  int i;

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

t_map *convert_to_map(char *file_content, int height)
{
  char **area;
  t_map *map;
  int i;
  int index;
  int width;

  map = malloc(sizeof(t_map));
  if (!map)
    return (NULL);

  area = allocate_area(height);
  if (!area)
  {
    free(map);
    return (NULL);
  }
  i = 0;
  index = 0;
  while (i < height)
  {
    char *row;
    row = extract_line(file_content, &index);
    if (!row)
    {
      ft_putstr_fd("Error\nMemory allocation failed\n", 2);
      while (i > 0)
        free(area[--i]);
      free(area);
      free(map);
      return (NULL);
    }
    width = ft_strlen(row);
    area[i] = row;
    i++;
  }
  area[height] = NULL;
  map->height = height;
  map->width = width;
  map->area = area;
  return (map);
}

char *read_file_content(int fd)
{
  char buffer[MAX_BUFFER_SIZE];
  char *file_content;
  int bytes_read;
  size_t total_size;

  file_content = NULL;
  total_size = 0;
  bytes_read = read(fd, buffer, MAX_BUFFER_SIZE - 1);
  while (bytes_read > 0)
  {
    buffer[bytes_read] = '\0';
    file_content = resize_content(
        file_content, total_size, bytes_read, buffer);
    if (!file_content)
      return (NULL);
    total_size += bytes_read;
    bytes_read = read(fd, buffer, MAX_BUFFER_SIZE - 1);
  }
  return (file_content);
}

void set_map_assets(t_map *map, int *players, int *collectibles, int *exits, int *unknowns)
{
  int i;
  int j;

  i = 0;
  while (map->area[i])
  {
    j = 0;
    while (map->area[i][j])
    {
      if (map->area[i][j] == 'P')
        (*players)++;
      else if (map->area[i][j] == 'C')
        (*collectibles)++;
      else if (map->area[i][j] == 'E')
        (*exits)++;
      else if (map->area[i][j] != '1' && map->area[i][j] != '0')
        (*unknowns)++;
      j++;
    }
    i++;
  }
}

t_map *load_map_from_file(char *filename)
{
  int fd;
  int height;
  t_map *map;
  char *file_content;

  fd = open(filename, O_RDONLY);
  if (fd < 0)
  {
    ft_putstr_fd("Error\nCould not open map file\n", 2);
    return (NULL);
  }
  file_content = read_file_content(fd);
  close(fd);
  if (!file_content)
    return (NULL);
  height = count_lines(file_content);
  map = convert_to_map(file_content, height);
  set_map_assets(map, &map->total_players, &map->total_collectibles, &map->total_exits, &map->total_unknowns);
  free(file_content);
  return (map);
}
