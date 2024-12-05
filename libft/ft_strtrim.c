/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcurtido <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:30:14 by jcurtido          #+#    #+#             */
/*   Updated: 2024/10/08 16:50:59 by jcurtido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j > i && ft_strchr(set, s1[j]))
		j--;
	len = j - i + 1;
	if (len == 0)
		return (ft_strdup(""));
	new_str = ft_substr(s1, i, len);
	return (new_str);
}
/*#include <stdio.h>
int	main(void)
{
	char	*str1 = "           Hola!           ";
	char	*str2 = "        Hola, Mundo!            ";
	char	*str3 = ",,,,,,,,,,,,,,,,";
	char	*set = ",";
	char	*answer1;
	char	*answer2;
	char	*answer3;

	answer1 = ft_strtrim(str1, set);
	answer2 = ft_strtrim(str2, set);
	answer3 = ft_strtrim(str3, set);
	//printf("primer resultado = %s\n", answer1);
	//printf("segundo resultado = %s\n", answer2);
	printf("tercer resultado = %s\n", answer3);
	return (1);
}*/
