/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamini <aamini@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 16:40:00 by aamini            #+#    #+#             */
/*   Updated: 2025/05/08 16:23:56 by aamini           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*word_dup(char const *s, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = s[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

static void	free_array(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	fill_words(char **result, char const *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[j] = word_dup(s, start, i);
			if (!result[j])
				return (j);
			j++;
		}
		else
			i++;
	}
	return (-1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;
	int		fail_index;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	fail_index = fill_words(result, s, c);
	if (fail_index >= 0)
	{
		free_array(result, fail_index);
		return (NULL);
	}
	result[word_count] = NULL;
	return (result);
}

// #include <stdio.h>
// int main ()
// {
// 	char *str = "It.is.my.str.ing";
// 	char c = 'm';
// 	char **splitedstrings = ft_split(str, c);
// 	int i = 0;
// 	while(splitedstrings[i])
// 	{
// 		printf("%s \n" , splitedstrings[i]);
// 		i++;
// 	}
// 	return (0);
// }
