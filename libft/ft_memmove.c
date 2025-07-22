/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:51:45 by aamini            #+#    #+#             */
/*   Updated: 2025/04/30 19:00:00 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char str[] = "memmove can handle overlapping";
// 	printf("Before ft_memmove: %s\n", str);
//
// 	ft_memmove(str + 5, str, 10);
// 	printf("After ft_memmove: %s\n", str);
//
// 	char str2[] = "memmove can handle overlapping";
// 	memmove(str2 + 5, str2, 10);
// 	printf("After memmove: %s\n", str2);
//
// 	return (0);
// }
