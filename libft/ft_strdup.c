/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:36:13 by aamini            #+#    #+#             */
/*   Updated: 2025/05/09 19:21:54 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		size;
	int		i;
	char	*copy;

	i = 0;
	size = ft_strlen(src);
	copy = (char *)malloc(size + 1);
	if (!copy)
		return (0);
	while (i < size + 1)
	{
		copy[i] = src[i];
		i ++;
	}
	return (copy);
}
// #include <stdio.h>
// int main()
// {
// 	char str[] = "Helloo";
// 	printf("%s" , ft_strdup(str));
// 	return (0);
// }