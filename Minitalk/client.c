/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:57:02 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/04 17:57:02 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "Libft/libft.h"
#include <signal.h>
#include <string.h>
#include <stdio.h>

void	send_signal(int pid, char c)
{
	int i;
	char temp_c;

	i = 8;
	temp_c = c;
	while (i > 0)
	{
		i--;
		temp_c = c >> i;
		if (temp_c % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(10);
	}
}

int main(int ac, char **av)
{
	int pid;
	int i;

	if (ac != 3)
		return(ft_printf("Usage: %s <pid> <message>\n.", av[0]));
	pid = ft_atoi(av[1]);
	i = -1;
	while (av[2][++i])
		send_signal(pid, av[2][i]);
	send_signal(pid, 0);
	return (0);
}