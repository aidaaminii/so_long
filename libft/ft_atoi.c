/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:50:38 by aamini            #+#    #+#             */
/*   Updated: 2025/05/08 18:14:26 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]) == 1)
	{
		result = result * 10;
		result = result + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

// #include <stdio.h> 
// int	main(void)
// {
// 	printf("1: %d\n", ft_atoi("42"));
// 	printf("2: %d\n", ft_atoi("   -123"));
// 	printf("3: %d\n", ft_atoi("+456"));
// 	printf("4: %d\n", ft_atoi("   +0"));
// 	printf("5: %d\n", ft_atoi("   00123"));
// 	printf("6: %d\n", ft_atoi("abc123"));     
// 	printf("7: %d\n", ft_atoi("123abc"));
// 	return (0);
// }