/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:58:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/24 14:15:00 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"
#include "../../libft/inc/ft_printf.h"
#include <stdio.h>

int	g_bit;

static char *final_print(char *str)
{
	ft_putstr_fd(str, 1);
	free(str);
	str = NULL;
	return (str);
}

static char *concatenate_char(char *str, char c)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	if (!str)
		str = ft_calloc(1, 1);
	len = ft_strlen(str);
	res = ft_calloc(len + 2, sizeof(char));
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = c;
	free(str);
	return (res);
}

static void	print_string(pid_t pid)
{
	static int	i = 0;
	static char	c = 0;
	static char	*str = NULL;
	static char	buffer[BUFFER_SIZE + 1] = {0};

	if (g_bit == 0)
		buffer[i] = 0;
	else
		buffer[i] = 1;
	i++;
	if (i == BUFFER_SIZE)
	{
		c = 0;
		i = -1;
		while (++i < BUFFER_SIZE)
			c |= buffer[i] << (BUFFER_SIZE - i - 1);
		str = concatenate_char(str, c);
		i = 0;
	}
	kill(pid, SIGUSR1);
	if (c == '\0')
		str = final_print(str);
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
	sa.sa_flags = SA_RESTART | SA_SIGINFO | SA_NODEFER;
	if (sigaction(SIGUSR1, &sa, 0) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sa, 0) == -1)
		return (1);
	ft_printf("%d\n", getpid());
	while (1)
		pause();
	return (0);
}
