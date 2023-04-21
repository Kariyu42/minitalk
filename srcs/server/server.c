/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:58:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/21 17:20:43 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"
#include "../../libft/inc/ft_printf.h"

int	g_bit = 0;

static void	print_char(int num)
{
	char	c;

	c = (char)num;
	ft_printf("le caractere = %c\n", c);
}

static void	print_string(pid_t pid)
{
	
	static int	binary = 0;

	if (g_bit == 0)
		binary =
}

static void	signal_handler(int signal, siginfo_t *sa, void *content)
{
	(void)content;
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
	sa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sa, 0);
	sigaction(SIGUSR2, &sa, 0);
	ft_printf("%d\n", getpid());
	while (1)
		sleep(1);
	return (0);
}
