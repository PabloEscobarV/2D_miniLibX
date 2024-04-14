/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filesize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:48:03 by blackrider        #+#    #+#             */
/*   Updated: 2024/04/10 14:49:48 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

long	filesize(const char *filename)
{
	long	size;
	char	tmp;
	int		file;

	file = open(filename, O_RDONLY);
	if (file < 3)
		return (-1);
	size = 0;
	while (read(file, &tmp, sizeof(char)))
		++size;
	close(file);
	return (size);
}
