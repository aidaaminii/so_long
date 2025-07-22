/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:20:00 by aamini            #+#    #+#             */
/*   Updated: 2025/05/03 17:20:00 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main(void)
// {
// 	// Write to stdout (terminal)
// 	ft_putchar_fd('A', 1);
// 	ft_putchar_fd('i', 1);
// 	ft_putchar_fd('d', 1);
// 	ft_putchar_fd('a', 1);
// 	ft_putchar_fd('\n', 1);
// 	return (0);
// }
