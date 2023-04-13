/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:00:08 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/13 11:09:12 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	ft_take_precision(const char *format, t_flags *tab, int i)
{
	int	res;

	res = 0;
	while (format[i] >= '0' && format[i] <= '9')
	{
		res = res * 10 + (format[i] - '0');
		i++;
	}
	tab->precision = res;
}

void	ft_get_precision(const char *format, t_flags *tab, int i)
{
	tab->precision = 0;
	tab->check_precision = 0;
	while (format[i] && !ft_locate_format("cspdiuxX%", format[i]))
	{
		if (format[i] == '.')
		{
			tab->check_precision = 1;
			i++;
			if (format[i] >= '0' && format[i] <= '9')
				ft_take_precision(format, tab, i);
			return ;
		}
		i++;
	}
}
