/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:17:27 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/26 16:38:02 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_fd(int fd, char *stash)
{
	char	*temp;
	int		check_read;

	if (!fd || stash)
		return (NULL);
	temp = malloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	check_read = 1;
	while (check_read && !get_good_size(stash))
	{
		check_read = read(fd, temp, BUFFER_SIZE);
		if ((!check_read && !stash) || check_read == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[check_read] = 0;
		if (stash && temp)
			stash = ft_strjoin(stash, temp);
		else
			stash = ft_strjoin("", temp);
	}
	free(temp);
	return (stash);
}

char	*fill_line(char	*stash)
{
	char	*list;
	int		i;

	if (!stash)
		return (NULL);
	list = malloc(get_good_size(stash) + 1);
	if (!list)
		return (NULL);
	i = -1;
	while (stash[++i] && stash[i] != '\n')
		list[i] = stash[i];
	if (stash[i] == '\n')
		list[i] = stash[i];
	list[++i] = 0;
	return (list);
}

char	*clear_stash(char *stash)
{
	char	*temp;
	int		i;
	int		j;

	if (!stash)
		return (NULL);
	i = get_good_size(stash);
	temp = malloc(ft_strlen(stash) - i + 1);
	if (!temp)
		return (NULL);
	j = -1;
	while (stash[++j + i])
		temp[j] = stash[j + i];
	temp[j] = 0;
	free(stash);
	if (temp[0] == 0)
	{
		free(temp);
		temp = NULL;
		return(temp);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	stash = read_fd(fd, stash);
	line = fill_line(stash);
	stash = clear_stash(stash);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
int main(void)
{
	int	fd;
	
	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}