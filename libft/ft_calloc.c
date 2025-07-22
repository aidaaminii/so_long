/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:49:57 by aamini            #+#    #+#             */
/*   Updated: 2025/05/09 16:34:49 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*address;
	size_t	total_size;

	total_size = count * size;
	if (total_size == 0)
		return (malloc(0));
	if (total_size > INT_MAX)
		return (NULL);
	else
	{
		address = malloc(total_size);
		if (address == NULL)
			return (NULL);
		ft_bzero(address, total_size);
		return (address);
	}
}

// #include <stdio.h>
// int main(void)
// {
// 	int size = 12;
// 	char *array = (char *)ft_calloc(size, 1);
// 	int i = 0;
// 	if(array != NULL)
// 	{
// 		while(i < size)
// 		{
// 			printf("%d", array[i]);
// 			i++;
// 		}
// 		printf("\nsize %d\n", i);
// 	}
// 	else
// 	{
// 		printf("%s" , "Failed");
// 	}
// 	return (0);
// }