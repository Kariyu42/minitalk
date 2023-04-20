/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:58:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/20 18:59:40 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"
#include "../../libft/inc/ft_printf.h"

int	main(void)
{
	pid_t	pid;
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	sa.sa_handler = &handle_signals;
	// sa.sa_flags = ;
	// sa.sa_mask = ;
	// sa.sa_sigaction = function;
	// sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	pid = getpid();
	ft_printf("%d\n", pid);
	while (1)
		sleep(1);
	return (0);
}
