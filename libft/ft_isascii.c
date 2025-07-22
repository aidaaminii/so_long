/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:51:17 by aamini            #+#    #+#             */
/*   Updated: 2025/04/28 18:41:46 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
// int	main(void)
// {
// 	printf("Test with 65 ('A'): %d\n", ft_isascii(65));      
// 	printf("Test with 127: %d\n", ft_isascii(127));         
// 	printf("Test with 128: %d\n", ft_isascii(128));        
// 	printf("Test with -1: %d\n", ft_isascii(-1));
// 	return (0);
// }