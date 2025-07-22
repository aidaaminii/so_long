/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:52:10 by aamini            #+#    #+#             */
/*   Updated: 2025/04/29 16:48:19 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count ++;
	}
	return (count);
}
// #include <stdio.h>
// int   main()
// {
// 	printf( "%d" , ft_strlen("Hello, , # ,11"));
// 	printf( "%d" , ft_strlen("dshhd"));
// 	return (0);
// }