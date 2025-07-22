/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:51:26 by aamini            #+#    #+#             */
/*   Updated: 2025/04/28 18:46:56 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
// int	main(void)
// {
// 	printf("Test with 'A': %d\n", ft_isprint('A')); 
// 	printf("Test with '\\t' (tab): %d\n", ft_isprint('\t'));  
// 	return (0);
// }