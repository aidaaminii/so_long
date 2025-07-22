/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:00:00 by aamini            #+#    #+#             */
/*   Updated: 2025/05/03 17:00:00 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (s == NULL || f == NULL)
	{
		return (NULL);
	}
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (result == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}

// #include <stdio.h>
// char example_func(unsigned int i, char c)
// {
// 	return (c + i);
// }
// 
// char uppercase(unsigned int i, char c)
// {
// 	(void)i;
// 	if (c >= 'a' && c <= 'z')
// 		return (c - 32);
// 	return (c);
// }
// 
// int main(void)
// {
// 	char *result;
// 	
// 	result = ft_strmapi("hello", example_func);
// 	printf("With example_func: %s\n", result);
// 	free(result);
// 	
// 	result = ft_strmapi("hello world", uppercase);
// 	printf("With uppercase: %s\n", result);
// 	free(result);
// 	
// 	return (0);
// }
