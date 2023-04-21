/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:40:38 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/21 16:49:38 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"
#include "../../libft/inc/ft_printf.h"

/*
	int	main(argc argv)
	{
		declarer struct sigaction;
		pid_t pid;

		send through a fonction the pid and the argv[2]
	}
*/

int	g_wait;

void	convert_binary(pid_t pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	bit = 0;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_wait)
		{
			ft_printf("j'attends g_wait\n");
			sleep(1);
		}
		g_wait = 0;
		i--;
	}
}

void	send_message(pid_t pid, char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		convert_binary(pid, message[i]);
		i++;
	}
	convert_binary(pid, '\0');
}

static void handle_sig(int signal)
{
	if (signal == SIGUSR1)
		g_wait = 1;
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_printf("WARNING!\nUsage: ./client [pid of the server] [string to display]\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &handle_sig;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, 0);
	send_message(pid, argv[2]);
	return (0);
}
