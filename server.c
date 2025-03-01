/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 17:28:00 by oobbad            #+#    #+#             */
/*   Updated: 2025/02/28 17:11:10 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle(int sig, siginfo_t *info, void *n)
{
	static int bite = 7;
	static char c = 0;
	static int current_pid = 0;
	
	if (current_pid != info->si_pid)
	{
		current_pid = info->si_pid;
        bite = 7;
        c = 0;
	}
	if (sig == SIGUSR1)
		c = (c | (1 << bite));
	bite--;
	if (bite < 0)
	{
		write (1, &c, 1);
		bite = 7;
		c = 0;
	}
	kill (current_pid, SIGUSR1);
	//kill (current_pid, 0);
}

int main ()
{
	struct sigaction sa;
	
	sa.sa_sigaction = handle;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr("PID: ");
	ft_putnbr_fd (getpid(), 1);
	write (1, "\n", 1);
	while (1);
	return 0;
}
