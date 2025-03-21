/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaterna <mmaterna@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 14:46:48 by mmaterna          #+#    #+#             */
/*   Updated: 2025/03/20 19:06:23 by mmaterna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	ft_printf("otrzymano sygnal %d\n", signum);
}

int	main(void)
{
	signal(SIGUSR1, signal_handler);
	ft_printf("Server is running! It's PID is: %d\n", getpid());

	while (1)
		usleep(100);
	return (0);
}
