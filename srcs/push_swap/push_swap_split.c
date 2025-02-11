/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trietpham <trietpham@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 14:47:04 by trietpham         #+#    #+#             */
/*   Updated: 2025/02/08 14:48:00 by trietpham        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static int count_words(char *s, char c)
{
    int count = 0;

    while (*s)
    {
        while (*s == c) // Skip delimiter characters
            ++s;
        if (*s && *s != c) // If we find a word
        {
            ++count;
            while (*s && *s != c) // Move to the end of the word
                ++s;
        }
    }
    return count;
}


static char *get_next_word(char *s, char c, int *cursor)
{
    char *next_word;
    int len = 0, i = 0;

    while (s[*cursor] == c) // Skip delimiters
        (*cursor)++;
    while (s[*cursor + len] && s[*cursor + len] != c) // Get word length
        len++;

    next_word = malloc(sizeof(char) * (len + 1)); // Allocate memory
    if (!next_word)
        return (NULL);
    
    while (s[*cursor] && s[*cursor] != c) // Copy the word
        next_word[i++] = s[(*cursor)++];
    next_word[i] = '\0';
    return (next_word);
}

char **push_swap_split(char *s, char c)
{
    int words_count = count_words(s, c);
    char **result_array;
    int cursor = 0, i = 0;

    if (words_count == 0)
        return (NULL);

    result_array = malloc(sizeof(char *) * (words_count + 1)); // No extra space
    if (!result_array)
        return (NULL);

    while (i < words_count)
        result_array[i++] = get_next_word(s, c, &cursor);

    result_array[i] = NULL; // Null terminate array
    return (result_array);
}
