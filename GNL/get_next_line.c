/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:04:45 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/18 13:10:44 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd)
{
	char		*str;
	static char	buffer[9999];
	static int	len;
	int			i;
	int			j;
	int			k;

	i = -1;
	if (!len)
		len = 0;
	j = len;
	k = len;
	if (!*buffer)
		read(fd, buffer, sizeof(buffer));
	while (buffer[len] != '\n' && buffer[len])
		len++;
	if (buffer[len - 1] == 0)
		return(NULL);
	str = malloc(len - j + 1);
	if (!str)
		return (NULL);
	while (++i + j < len + 1)
		str[i] = buffer[k++];
	len++;
	return (str);
}

int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY);
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
}
