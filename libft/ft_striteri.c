/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:10:00 by aamini            #+#    #+#             */
/*   Updated: 2025/05/03 17:10:00 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// void example_func(unsigned int i, char *c)
// {
// 	printf("Index: %u, Character: %c\n", i, *c);
// }
// 
// void uppercase_inplace(unsigned int i, char *c)
// {
// 	(void)i;
// 	if (*c >= 'a' && *c <= 'z')
// 		*c = *c - 32;
// }
// 
// int main(void)
// {
// 	char str1[] = "hello";
// 	
// 	printf("Testing example_func:\n");
// 	ft_striteri(str1, example_func);
// 	
// 	char str2[] = "hello world";
// 	printf("\nBefore uppercase_inplace: %s\n", str2);
// 	ft_striteri(str2, uppercase_inplace);
// 	printf("After uppercase_inplace: %s\n", str2);
// 	
// 	return (0);
// }
