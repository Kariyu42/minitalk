/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:31:18 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/13 11:09:18 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static int	ft_hexalen(unsigned long num)
{
	unsigned long	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num)
	{
		i++;
		num = num / 16;
	}
	return (i);
}

void	ft_print_hexa(t_flags *tab, char *base)
{
	int				len;
	unsigned int	num;

	num = va_arg(tab->ap, unsigned int);
	if (num == 0 && !tab->precision && tab->check_precision)
		len = 0;
	else
		len = ft_hexalen(num);
	if (tab->hash && num > 0)
		tab->width -= 2;
	if (tab->zero && !tab->check_precision)
		hexa_zero_padd(num, len, tab, base);
	else if (tab->minus)
		hexa_left_wdth(num, len, tab, base);
	else
		hexa_wdth(num, len, tab, base);
}
