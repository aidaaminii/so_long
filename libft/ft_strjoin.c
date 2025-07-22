/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:10:00 by aamini            #+#    #+#             */
/*   Updated: 2025/05/03 16:10:00 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joined)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *s1 = "Hello ";
// 	char *s2 = "World!";
// 	char *joined;
// 	
// 	joined = ft_strjoin(s1, s2);
// 	printf("s1: '%s'\n", s1);
// 	printf("s2: '%s'\n", s2);
// 	printf("joined: '%s'\n", joined);
// 	free(joined);
// 	
// 	joined = ft_strjoin("", "test");
// 	printf("empty + 'test': '%s'\n", joined);
// 	free(joined);
// 	
// 	joined = ft_strjoin("test", "");
// 	printf("'test' + empty: '%s'\n", joined);
// 	free(joined);
// 	
// 	return (0);
// }
