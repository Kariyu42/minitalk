/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:58:02 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/18 12:08:22 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/server.h"
#include "../../libft/inc/ft_printf.h"

function(int signal, ...)
{
	
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = ;
	sa.sa_flags = ;
	sa.sa_mask = ;
	sa.sa_sigaction = function;
	sigemptyset(&sa.sa_mask);
	ft_printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	return (0);
}
