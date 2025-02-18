/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tripham <tripham@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:47:04 by trietpham         #+#    #+#             */
/*   Updated: 2025/02/18 20:08:08 by tripham          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	count_words(char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			++s;
		if (*s && *s != c)
		{
			++count;
			while (*s && *s != c)
				++s;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c, int *cursor)
{
	char	*next_word;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[*cursor] == c)
		(*cursor)++;
	while (s[*cursor + len] && s[*cursor + len] != c)
		len++;
	next_word = malloc(sizeof(char) * (len + 1));
	if (!next_word)
		return (NULL);
	while (s[*cursor] && s[*cursor] != c)
		next_word[i++] = s[(*cursor)++];
	next_word[i] = '\0';
	return (next_word);
}

char	**push_swap_split(char *s, char c)
{
	int		words_count;
	char	**result_array;
	int		cursor;
	int		i;

	cursor = 0;
	i = 0;
	words_count = count_words(s, c);
	if (words_count == 0)
		return (NULL);
	result_array = malloc(sizeof(char *) * (words_count + 1));
	if (!result_array)
		return (NULL);
	while (i < words_count)
	{
		result_array[i] = get_next_word(s, c, &cursor);
		if (!result_array[i])
		{
			while (i > 0)
				free (result_array[--i]);
			return (free(result_array), NULL);
		}
		i++;
	}
	return (result_array[i] = NULL, result_array);
}
