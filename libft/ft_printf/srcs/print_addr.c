/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 22:50:49 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/13 11:09:17 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

int	hexa_len(unsigned long num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num)
	{
		num /= 16;
		i++;
	}
	return (i);
}

void	ft_base_convert(unsigned long num, t_flags *tab, char *base)
{
	if (num >= 16)
	{
		ft_base_convert(num / 16, tab, base);
		ft_base_convert(num % 16, tab, base);
	}
	else
		tab->len += write(1, &base[num], 1);
}

static void	print_left_p(unsigned long num, int len, t_flags *tab)
{
	int	i;

	i = -1;
	tab->len += write(1, "0x", 2);
	ft_base_convert(num, tab, "0123456789abcdef");
	if (tab->width > len)
		while (++i < tab->width - len - 2)
			tab->len += write(1, " ", 1);
}

static void	print_wdth_p(unsigned long num, int len, t_flags *tab)
{
	int	i;

	i = -1;
	if (tab->width > len)
		while (++i < tab->width - len - 2)
			tab->len += write(1, " ", 1);
	tab->len += write(1, "0x", 2);
	ft_base_convert(num, tab, "0123456789abcdef");
}

void	ft_print_p(t_flags *tab)
{
	unsigned long	num;
	int				len;

	num = va_arg(tab->ap, unsigned long);
	len = hexa_len(num);
	if (tab->minus)
		print_left_p(num, len, tab);
	else
		print_wdth_p(num, len, tab);
}
