/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polenyc <polenyc@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 21:38:29 by polenyc           #+#    #+#             */
/*   Updated: 2023/11/21 00:50:00 by polenyc          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static char	**free_matrix(char **end, char **start)
{
	while (end >= start)
		free(*end--);
	free(start);
	return (NULL);
}

static char	**create_str_m(char **arr, char const *s, char c)
{
	size_t	size;
	char	**arr_tmp;

	arr_tmp = arr;
	size = 0;
	while (*s != '\0')
	{
		if (*s != c)
			++size;
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
		{
			*arr_tmp = malloc((size + 1) * sizeof(char));
			if (*arr_tmp == NULL)
				return (free_matrix(arr_tmp, arr));
			++arr_tmp;
			size = 0;
		}
		++s;
	}
	return (arr);
}

static char	**create_matrix(char const *s, char c)
{
	size_t		size;
	char const	*str;
	char		**tmp;

	size = 0;
	str = s;
	while (*str != '\0')
	{
		if (*str != c && (*(str + 1) == c || *(str + 1) == '\0'))
			++size;
		++str;
	}
	tmp = malloc((size + 1) * sizeof(char *));
	if (!tmp)
		return (NULL);
	tmp[size] = NULL;
	return (create_str_m(tmp, s, c));
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	**arr_tmp;
	int		i;

	arr = create_matrix(s, c);
	if (!arr)
		return (NULL);
	arr_tmp = arr;
	while (*s != '\0')
	{
		i = 0;
		while (*s != c && *s != '\0')
			(*arr)[i++] = *s++;
		if (i > 0)
		{
			(*arr)[i++] = '\0';
			++arr;
			if (*s == '\0')
				return (arr_tmp);
		}
		++s;
	}
	return (arr_tmp);
}
