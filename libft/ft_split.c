/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:08:11 by jcurtido          #+#    #+#             */
/*   Updated: 2024/10/08 16:51:18 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	split_free_words(char **words, size_t count)
{
	size_t	i;

	if (words)
	{
		i = 0;
		while (i < count)
		{
			if (words[i])
				free(words[i]);
			i++;
		}
		free (words);
	}
}

static char	*split_fill_word(char const **str_pos, char c)
{
	const char	*start;
	char		*new_word;

	while (**str_pos == c && **str_pos != '\0')
		(*str_pos)++;
	if (**str_pos == '\0')
		return (NULL);
	start = *str_pos;
	while (**str_pos != c && **str_pos != '\0')
		(*str_pos)++;
	new_word = ft_substr(start, 0, *str_pos - start);
	return (new_word);
}

static size_t	split_count_words(char const *s, char c)
{
	size_t	i;
	size_t	in_word;
	size_t	words;

	i = 0;
	in_word = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			words++;
		}
		else if (s[i] == c && in_word == 1)
			in_word = 0;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	words_count;
	size_t	i;

	if (!s)
		return (NULL);
	words_count = split_count_words(s, c);
	words = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!words)
		return (NULL);
	i = 0;
	while (i < words_count)
	{
		words[i] = split_fill_word(&s, c);
		if (!words[i])
		{
			split_free_words(words, i);
			return (NULL);
		}
		i++;
	}
	words[i] = NULL;
	return (words);
}
/*
#include <stdio.h>
static void test_split(const char *str, char c) {
    char **words;
    int i = 0;

    printf("Testing ft_split with string: \"%s\" and separator: '%c'\n", str, c);
    words = ft_split(str, c);

    if (words == NULL) {
        printf("Returned NULL\n");
        return;
    }

    while (words[i]) {
        printf("str = \"%s\"\n", words[i]);
        free(words[i]);  // Liberar la memoria de cada palabra
        i++;
    }
    free(words); // Liberar la memoria del array de punteros
}

int main(void) {
    // Pruebas
    test_split("Nadie es luz de si mismo; ni el sol.", ' ');
    test_split("hello,world", ',');
    test_split("abc,,,def", ',');
    test_split("a b c d e", ' ');
    test_split("", ' ');
    test_split("     ", ' ');  // Solo espacios
    test_split("one", ' ');    // Sin separadores
    test_split(NULL, ' ');      // Caso de entrada NULL

    return 0;
}*/
