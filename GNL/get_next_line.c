/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:04:45 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/17 18:56:24 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char		*str;
	static char	buffer[1024];
	static int	len;
	int			i;
	int			j;

	i = -1;
	j = 0;
	if (!len)
		len = 0;
	if (!*buffer)
		read(fd, buffer, sizeof(buffer));
	while (buffer[len] != '\n' && buffer[len])
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	while (++i < len + 1)
		str[i] = buffer[i];
	len++;
	str[i] = 0;
	return (str);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}
