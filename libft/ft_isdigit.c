/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:51:21 by aamini            #+#    #+#             */
/*   Updated: 2025/04/28 18:44:14 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
// int	main(void)
// {
// 	printf("Test with '5': %d\n", ft_isdigit('5'));
// 	printf("Test with 'a': %d\n", ft_isdigit('a'));  
// 	printf("Test with 48 ('0'): %d\n", ft_isdigit(48));  
// 	printf("Test with 65 ('A'): %d\n", ft_isdigit(65));      
// 	return (0);
// }