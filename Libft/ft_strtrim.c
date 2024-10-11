/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 17:33:52 by pboucher          #+#    #+#             */
/*   Updated: 2024/10/11 18:13:54 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_test(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	l = ft_strlen(set);
	j = ft_strlen(s1);
	while (s1[i] == set[i] && s1[i] && set[i])
		i++;
	while (s1[j--] == set[l--] && s1[j--] && set[l--])
		i++;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		k;
	int		l;

	j = ft_test(s1, set);
	str = malloc(sizeof(char) * (j + 1));
	if (!str)
		return (NULL);
	i = 0;
	k = 0;
	l = ft_strlen(set);
	j = ft_strlen(s1);
	while (s1[i] == set[i] && s1[i] && set[i])
		i++;
	while (s1[j] == set[l--] && s1[j] && set[l--])
		j--;
	while (i < j)
		str[k++] = s1[i++];
	str[k] = 0;
	return (str);
}
