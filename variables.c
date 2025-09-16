/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>          +#+  +:+       +#+      	  */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 00:00:00 by aamini           #+#    #+#              */
/*   Updated: 2025/07/29 00:00:00 by aamini          ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_variables(t_game *game)
{
	find_char(game->map, 'E', &game->exit_x_position, &game->exit_y_position);
	game->collected_ones = 0;
	game->moves = 0;
	return (0);
}
