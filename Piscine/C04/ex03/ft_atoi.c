/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 10:13:50 by pboucher          #+#    #+#             */
/*   Updated: 2024/08/19 18:54:11 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	temp;
	int	negatif;

	i = 0;
	temp = 0;
	negatif = 0;
	while (((str[i] >= 9 && str[i] <= 13) 
		|| str[i] == 32) && str[i] != '\0')
		i++;
	while ((str[i] == 43 || str[i] == 45) && str[i] != '\0')
	{
		if (str[i] == 45)
			negatif++;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		temp = 10 * temp + (str[i] - '0');
		i++;
	}
	if (negatif % 2 == 1)
		temp = -temp;
	return (temp);
}
