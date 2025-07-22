/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:52:24 by aamini            #+#    #+#             */
/*   Updated: 2025/05/09 19:33:18 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char*str, int chr)
{
	int	i;

	i = ft_strlen (str);
	while (i >= 0)
	{
		if (str[i] == (char)chr)
			return ((char *)&str[i]);
		i--;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
//     char sentence[] = "Libft is fun!";
//     char *found = ft_strrchr(sentence, 'i');

//     if (found)
//         printf("Last 'i' found at: %s\n", found);
//     else
//         printf("Character not found.\n");

//     return 0;
// }