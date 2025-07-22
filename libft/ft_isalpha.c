/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:51:12 by aamini            #+#    #+#             */
/*   Updated: 2025/04/28 18:38:43 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	printf("Test with 'A': %d\n", ft_isalpha('A')); // باید چاپ کنه 1
// 	printf("Test with 'z': %d\n", ft_isalpha('z')); // باید چاپ کنه 1
// 	printf("Test with '5': %d\n", ft_isalpha('5')); // باید چاپ کنه 0
// 	printf("Test with '*': %d\n", ft_isalpha('*')); // باید چاپ کنه 0
// 	return (0);
// }