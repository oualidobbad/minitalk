/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:52:56 by oobbad            #+#    #+#             */
/*   Updated: 2025/03/01 09:46:07 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int flag = 0;

void		handl(int sig)
{
	if (sig == SIGUSR1)
		flag = sig;
	// else if (s)
	// {
	// 	ft_putstr("salit");
	// 	exit (0);
	// }
}

void send_signal(int pid, char c)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i & 1) == 1)
			kill (pid, SIGUSR1);
		else
			kill (pid, SIGUSR2);
		while (flag == 0);
		flag = 0;
		i--;
	}
}

int main (int ac, char **av)
{
	int pid;
	int i;

	pid = ft_atoi (av[1]);
	i = 0;
	signal(SIGUSR1, handl);
	signal(SIGUSR2, handl);
	if (ac != 3)
		return 0;
	while (av[2][i])
		send_signal(pid, av[2][i++]);
	ft_putstr("salit\n");
	return 0;
}
