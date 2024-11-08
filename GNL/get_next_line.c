/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 08:17:27 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/03 10:38:46 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_fd(int fd, char *stash)
{
	char	*temp;
	int		check_read;

	check_read = 1;
	temp = NULL;
	while (check_read && !ft_strchr(stash, '\n', 0))
	{
		temp = ft_calloc(BUFFER_SIZE + 1, 1);
		if (!temp)
			return (NULL);
		check_read = read(fd, temp, BUFFER_SIZE);
		if (check_read == -1 || (check_read == 0 && stash[0] == '\0'))
		{
			free(temp);
			free(stash);
			return (NULL);
		}
		temp[check_read] = 0;
		stash = ft_strjoin(stash, temp);
	}
	return (stash);
}

static char	*clear_stash(char *stash)
{
	char	*temp;
	int		i;

	if (!stash || !stash[0])
		return (NULL);
	i = ft_strchr(stash, '\n', 1);
	if (i == ft_strlen(stash))
	{
		free(stash);
		return (NULL);
	}
	temp = ft_substr(stash, i, ft_strlen(stash));
	free(stash);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
		stash = ft_calloc(1, 1);
	if (!stash)
		return (NULL);
	stash = read_fd(fd, stash);
	line = ft_substr(stash, 0, ft_strchr(stash, '\n', 1));
	stash = clear_stash(stash);
	return (line);
}

// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
// 	char *c;
// 	int fd;
// 	int i = 0;
// 	fd = open("text.txt", O_RDONLY);
// 	c = "";
// 	while (c)
// 	{
// 		c = get_next_line(fd);
// 		printf("%s", c);
// 		usleep(100000);
// 		i++;
// 	}
// 	printf("\n%d\n", i);
// }