/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:52:01 by aamini            #+#    #+#             */
/*   Updated: 2025/05/09 19:34:28 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_size;
	size_t	src_size;

	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	i = 0;
	if (size <= dest_size)
		return (size + src_size);
	while (src[i] != '\0' && (dest_size + i) < (size -1))
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest_size + src_size);
}
// #include <stdio.h>
// int   main()
// {
// 	printf( "%zu \n" , ft_strlcat("Hello World! jj","World" , 3));
// 	printf( "%zu \n\n" , strlcat("Hello World! jj","World" , 3));
// 	printf( "%zu \n" , ft_strlcat("bananananana test","nana " , 1));
// 	printf( "%zu \n" , ft_strlcat("&4    ') dogk!","World" , 10));
// 	return (0);
// }