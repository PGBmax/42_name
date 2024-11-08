/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboucher <pboucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:34:15 by pboucher          #+#    #+#             */
/*   Updated: 2024/11/04 18:34:15 by pboucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin(char *s1, char s2)
{
	char	*str;
	int		i;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + 2);
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i] = s2;
	str[i + 1] = 0;
	free(s1);
	s1 = NULL;
	return (str);
}

void	fill_str(char c, char *str)
{
	if (c == 0)
	{
		ft_printf(str);
		free(str);
		str = NULL;
	}
	else
		str = ft_strjoin(str, c);
}

void	handle_signal(int signal, siginfo_t *signals, void *context)
{
	static char	c;
	static char	*str = NULL;
	static int	index;

	(void)context;
	if (signal == SIGINT)
	{
		free(str);
		exit(0);
	}
	c |= (signal == SIGUSR1);
	index++;
	if (index == 8)
	{
		fill_str(c, str);
		index = 0;
		c = 0;
	}
	else
		c <<= 1;
	usleep(1);
	kill(signals->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	usr;

	sigemptyset(&usr.sa_mask);
	ft_printf("\n\e[36mPID: %d\n\n\e[37m", getpid());
	usr.sa_sigaction = handle_signal;
	usr.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &usr, NULL);
	sigaction(SIGUSR2, &usr, NULL);
	sigaction(SIGINT, &usr, NULL);
	while (1)
		pause();
	return (0);
}
