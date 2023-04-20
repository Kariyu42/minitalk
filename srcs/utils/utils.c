/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:59:08 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/20 18:52:18 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minitalk.h"
#include "../../libft/inc/ft_printf.h"

void	handle_signals(int signal)
{
	if (signal == SIGUSR1)
		SIGUSR1 = 0;
	else
		ft_printf("Je n'ai recu aucun signal...\n");
}
