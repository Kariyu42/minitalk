/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:58:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/24 09:08:04 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"
#include "../../libft/inc/ft_printf.h"

int	g_bit;

static void	print_string(pid_t pid)
{
	char		c;
	static int	i = 0;
	static char	buffer[BUFFER_SIZE + 1] = {0};

	if (g_bit == 0)
		buffer[i] = '0';
	else
		buffer[i] = '1';
	i++;
	if (i == 7)
	{
		c = 0;
		i = 0;
		while (i < BUFFER_SIZE)
		{
			c |= (buffer[i] - '0') << (BUFFER_SIZE - i - 1);
			ft_printf("%c", c);
			i++;
		}
		ft_putchar_fd(c, 1);
		ft_bzero(buffer, BUFFER_SIZE);
		i = 0;
	}
	kill(pid, SIGUSR1);
}

static void	signal_handler(int signal, siginfo_t *sa, void *ignore)
{
	(void)ignore;
	if (signal == SIGUSR1)
		g_bit = 0;
	else
		g_bit = 1;
	print_string(sa->si_pid);
}

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = &signal_handler;
	sa.sa_flags = SA_RESTART | SA_RESTART | SA_NODEFER;
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		return (1);
	ft_printf("%d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}
