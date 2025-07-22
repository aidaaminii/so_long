/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:52:06 by aamini            #+#    #+#             */
/*   Updated: 2025/05/09 19:09:22 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
// #include <stdio.h>
// int	main(void)
// {
// 	char	source[] = "Aida, Ahmadreza";
// 	char	destination[30];
// 	size_t	result;

// 	result = ft_strlcpy(destination, source, sizeof(destination));

// 	printf("Copied string: %s\n", destination);
// 	printf("Length of source: %zu\n", result);

// 	return (0);
// }