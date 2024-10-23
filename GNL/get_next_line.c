/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:54:31 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/23 19:02:12 by pboucher         ###   ########.fr       */
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
	stash[i + j] = 0;
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
	static t_buff	buff;
	char			*line;
	int				byte_read;
	int				limit;

	byte_read = 1;
	if (!buff.stash)
		buff.stash = "";
	if (!buff.i)
		buff.i = 0;
	limit = buff.i;
	while (byte_read)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (!byte_read)
			break ;
		buff.stash = fill_stash(buff.stash, buffer, byte_read);
	}
	while (buff.stash[buff.i] && buff.stash[buff.i] != '\n')
		buff.i++;
	buff.i++;
	line = fill_line(buff.stash, limit, buff.i - limit);
	return (line);
}

int	main(void)
{
	int	fd;
	int i = -1;

	fd = open("test.txt", O_RDONLY);
	while (++i < 9)
		printf("%s", get_next_line(fd));
}
