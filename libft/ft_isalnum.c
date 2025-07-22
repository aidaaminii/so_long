/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:51:06 by aamini            #+#    #+#             */
/*   Updated: 2025/04/28 18:34:35 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) == 1 || ft_isalpha(c) == 1)
		return (1);
	return (0);
}
// int	main(void)
// {
// 	char ch;

// 	ch = 'A';
// 	printf("Is '%c' alnum? %d\n", ch, ft_isalnum(ch));

// 	ch = '9';
// 	printf("Is '%c' alnum? %d\n", ch, ft_isalnum(ch));

// 	ch = '*';
// 	printf("Is '%c' alnum? %d\n", ch, ft_isalnum(ch));

// 	return (0);
// }
