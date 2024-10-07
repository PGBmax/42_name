/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:08:07 by pboucher          #+#    #+#             */
/*   Updated: 2024/08/26 22:02:08 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			j++;
			k++;
		}
		j = 0;
		while (sep[j] != '\0' && i < size - 1)
		{
			j++;
			k++;
		}
		i++;
	}
	return (k + 1);
}

char	*ft_strclone(int size, char **strs, char *sep, char *temp)
{
	int	j;
	int	k;
	int	i;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			temp[k] = strs[i][j];
			j++;
			k++;
		}
		j = 0;
		while (sep[j] != '\0' && i < size - 1)
		{
			temp[k] = sep[j];
			j++;
			k++;
		}
		i++;
	}
	return (temp);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*temp;

	if (size == 0)
		return (NULL);
	i = 0;
	len = str_len(size, strs, sep);
	temp = malloc(sizeof(char) * len);
	if (temp == NULL)
		return (NULL);
	while (i < len)
	{
		temp[i] = '\0';
		i++;
	}
	temp = ft_strclone(size, strs, sep, temp);
	return (temp);
}
