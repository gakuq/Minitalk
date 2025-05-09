/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:46:48 by mmaterna          #+#    #+#             */
/*   Updated: 2025/04/01 14:12:31 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static int	bit_count = 0;
	static char	c = 0;

	if (signum == SIGUSR1)
		c = (c << 1) | 0;
	else if (signum == SIGUSR2)
		c = (c << 1) | 1;

	bit_count++;
	if (bit_count == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		bit_count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	ft_printf("Server is running! It's PID is: %d\n", getpid());

	while (1)
		usleep(100);
	return (0);
}
