/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:16:50 by polenyc           #+#    #+#             */
/*   Updated: 2024/04/02 16:59:41 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	if (!str)
		return (count);
	while (str[count] != '\0')
		++count;
	return (count);
}

size_t	ft_filesize(char *filename)
{
	char	ch;
	int		file;
	size_t	size;

	file = open(filename, O_RDONLY);
	if (file < 3)
		return (-1);
	size = 0;
	while (read(file, &ch, 1))
		++size;
	close(file);
	return (size);
}
