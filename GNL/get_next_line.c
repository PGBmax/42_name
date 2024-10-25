/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:54:31 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/25 17:26:54 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*fill_stash(char *old, char *add, int max)
{
	char	*stash;
	int		i;
	int		j;

	i = -1;
	j = -1;
	stash = malloc(ft_strlen(old) + ft_strlen(add) + 1);
	if (!stash)
		return (NULL);
	while (old[++i])
		stash[i] = old[i];
	while (add[++j] && j < max)
		stash[i + j] = add[j];
	return (stash);
}

char	*fill_line(char *stash, int start, int size)
{
	char	*line;
	int		i;

	line = malloc(size + 1);
	if (!line || !stash[start])
		return (NULL);
	i = -1;
	while (++i < size)
		line[i] = stash[start + i];
	return (line);
}

char	*get_next_line(int fd)
{
	char			buffer[BUFFER_SIZE];
	static	t_buff	buff;
	char			*line;
	int				byte_read;

	byte_read = 1;
	line = NULL;
	if (!buff.stash && !buff.i && !buff.read)
	{
		buff.stash = "";
		buff.i = 0;
		buff.read = 0;
	}
	buff.limit = buff.i;
	while (byte_read && byte_read != buff.read)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (!byte_read)
			break ;
		buff.stash = fill_stash(buff.stash, buffer, byte_read);
		buff.read += byte_read;
	}
	while (buff.stash[buff.i] && buff.stash[buff.i] != '\n')
		buff.i++;
	if (buff.limit == buff.i)
		return (NULL);
	buff.i++;
	line = fill_line(buff.stash, buff.limit, buff.i - buff.limit);
	return (line);
}

int	main(void)
{
	int	fd;
	int i = 0;

	fd = open("test.txt", O_RDONLY);
	while (++i < 50)
		printf("%s", get_next_line(fd));
}
