/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_numflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:48:53 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/13 11:08:24 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	ft_check_addflags(int sign, t_flags *tab)
{
	if (tab->space && !sign)
		tab->len += write(1, " ", 1);
	else if (sign)
		tab->len += write(1, "-", 1);
	else if ((tab->space && tab->plus && !sign) || (tab->plus && !sign))
		tab->len += write(1, "+", 1);
}

void	ft_hexa_flags(unsigned int num, t_flags *tab)
{
	if (num > 0 && tab->hash)
	{
		if (tab->hash == 2)
			tab->len += write(1, "0x", 2);
		else if (tab->hash == 3)
			tab->len += write(1, "0X", 2);
	}
}
