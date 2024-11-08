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

#include "minitalk_bonus.h"

int	g_check = 0;

void	change_state(int sig)
{
	if (sig == SIGUSR2)
		exit (0);
	g_check = 1;
}

void	send_signal(int pid, char c)
{
	int		i;
	char	temp_c;

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
		usleep(1);
		signal(SIGUSR1, change_state);
		while (g_check == 0)
			pause();
		g_check = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac != 3)
	{
		ft_printf("\n\e[31mError !\n\e[32m");
		ft_printf("\e[32mCorrect Usage: %s <PID> <STR>\n", av[0]);
		ft_printf("\e[36mPID must be an unsigned int, and STR a char *.\n\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	if (pid <= 0 || kill(pid, 0))
	{
		ft_printf("\n\e[31mError !\n\e[32mNot a valid PID.\n");
		ft_printf("\e[36mPID must be an unsigned int.\n\n");
		return (0);
	}
	i = -1;
	while (av[2][++i] && av[2])
		send_signal(pid, av[2][i]);
	send_signal(pid, 0);
	return (0);
}
