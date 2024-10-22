/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:04:45 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/22 18:16:03 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int ft_strlen(char *s)
{
	int i;

	i = 0;
	if (!s)
		return (0);
	while(s[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*str;
	char		*temp;
	char		*temp2;
	static buffers buffer;
	int			i;
	int			j;
	int			k;

	i = -1;
	if (!buffer.len)
		buffer.len = 0;
	j = buffer.len;
	k = buffer.len;
	if (!*buffer.buffer)
		read(fd, buffer.buffer, sizeof(buffer.buffer));
	while (buffer.buffer[buffer.len] != '\n' && buffer.buffer[buffer.len])
		buffer.len++;
	if (buffer.buffer[buffer.len - 1] == 0 && BUFFER_SIZE != 1)
		return(NULL);
	str = malloc(buffer.len - j + 1);
	if (!str)
		return (NULL);
	while (++i + j < buffer.len + 1)
		str[i] = buffer.buffer[k++];
	str[i] = 0;
	if (buffer.buffer[buffer.len] == '\n' && BUFFER_SIZE == 1)
		read(fd, buffer.buffer, sizeof(buffer.buffer));
	else if (buffer.buffer[BUFFER_SIZE - 1] != 0 && buffer.len == BUFFER_SIZE)
	{
		i = -1;
		j = 0;
		buffer.len = 0;
		read(fd, buffer.buffer, sizeof(buffer.buffer));
		temp = get_next_line(fd);
		temp2 = malloc(ft_strlen(temp) + ft_strlen(str) + 1);
		if (!temp2)
			return (NULL);
		while(str[++i])
			temp2[i] = str[i];
		while (temp[j])
			temp2[i++] = temp[j++];
		free(str);
		free(temp);
		return (temp2);
	}
	buffer.len++;
	return (str);
}

int main(void)
{
	int fd;

	fd = open("caca.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}