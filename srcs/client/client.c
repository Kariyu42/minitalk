/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:40:38 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/18 13:52:04 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/client.h"
#include "../../libft/inc/ft_printf.h"

int	main(int argc, char **argv)
{
	pid_t	pid;
	if (argc != 3)
		return (0);
	pid = ft_atoi(argv[1]);
	signal();
	return (0);
}
