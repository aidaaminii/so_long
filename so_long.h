/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:06:13 by aamini            #+#    #+#             */
/*   Updated: 2025/07/24 17:14:32 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>     
# include <stdio.h>
# include <mlx.h>       

typedef struct s_game
{
	char	**map;
	int	width;
	int	height;
}	t_game;

char    **read_map(const char *file, t_game *game);
void    free_map(char **map);

#endif
