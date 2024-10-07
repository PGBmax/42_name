/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsaint-p <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 11:27:20 by jsaint-p          #+#    #+#             */
/*   Updated: 2024/08/25 17:27:53 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && i < n -1)
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int	verif(int ac, char *av)
{
	int	len;

	if (ac != 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	if (is_valid(av) == 0)
	{
		write(1, "error\n", 6);
		return (0);
	}
	len = str_len(av);
	if (len > 39)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	return (1);
}

char	*find_in_dict(int num, char *dict)
{
	char	*ptr;
	char	num_str[12];
	char	*newline;
	char	*result;
	int	i;
	int	j; 

	i = 0;
	j = 0;
	ptr = dict;
	sprintf(num_str, "%d: ", num);
	while (ptr[i] != '\0')
	{
		if (ptr[i] == num_str[0])
		{
			if (ft_strncmp(&ptr[i], num_str, str_len(num_str)) == 0)
			{
			newline = &ptr[i + str_len(num_str)];
				while (newline[j] != '\n' && newline[j] != '\0')
				{
					j++;
					result = malloc(j + 1);
					ft_strncpy(result, newline, j);
					result[j] = '\0';
					return (result);
				}
			}
		}
		i++;
	}
	return ("");
}

void	ft_case3(int num, char *dict)
{
	write(1, find_in_dict(num, dict), str_len(find_in_dict(num, dict)));
}

void	ft_case2(int num, char *dict)
{
	if (num < 20)
		ft_case3(num, dict);
	else
	{
		write(1, find_in_dict((num / 10) * 10, dict), str_len(find_in_dict((num / 10) * 10, dict)));
		if (num % 10 > 0)
		{
			write(1, "-", 1);
			ft_case3(num % 10, dict);
		}
	}
}

void	ft_case1(int num, char *dict)
{
	if (num > 0)
	{
		ft_case3(num / 100, dict);
		write(1, " hundred ", 9);
		if (num % 100 > 0)
		{
			write(1, "and ", 4);
			ft_case2(num % 100, dict);
		}
	}
}

int ft_atoi(char *str)
{
	int num;
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num);

}
void	str_analyze(char *str, char *dict)
{
	int	num;

	num = ft_ atoi(str);
	if (length % 3 == 0);
		ft_case1(num, dict);
	else if (length % 3 == 2)
		ft_case2(num, dict);
	else if (length % 3== 1)
		ft_case3(num, dict);
}

void	str_feur(char *str, char *dict)
{
	int len;
	int i;

	len = str_len(str);
	i = 0;
	while (i <= len)
	{
		str_analyze(str[i],dict)
		if (i % 3 == 0)
			i++;
		else if ()
	}

}

char	*load_dict()
{
	int	fd;
	char	small_buffer[1024];
	char	*buffer;
	int	total_size = 0;
	int	bytes_read;

	fd = open("numbers.dict", O_RDONLY);
	if (fd < 0)
	{
		write(1, "error\n", 6);
		return (NULL);
	}
	while ((bytes_read = read(fd, small_buffer, sizeof(small_buffer))) > 0)
		total_size += bytes_read;
	if (bytes_read < 0)
	{
		write(1, "Error reading file.\n", 20);
		close(fd);
		return (NULL);
	}
	buffer = malloc(total_size + 1);
	if (buffer == NULL)
	{
		write(1, "Memory allocation error.\n", 25);
		close(fd);
		return (NULL);
	}
	lseek(fd, 0, SEEK_SET);
	read(fd, buffer, total_size);
	buffer[total_size] = '\0';
	close(fd);
	return (buffer);
}

int	main(int argc, char **argv)
{
	char	*dict;

	if (!verif(argc, argv[1]))
		return (0);
	dict = load_dict();
	if (dict == NULL)
		return (0);
	str_cut(argv[1], dict);
	free(dict);
	return (1);
}
