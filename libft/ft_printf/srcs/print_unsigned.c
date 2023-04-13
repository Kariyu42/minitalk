/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:31:20 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/13 11:09:20 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	uint_pad_zero(char *str, int len, t_flags *tab)
{
	int	i;

	i = -1;
	ft_check_addflags(0, tab);
	while (++i < tab->width - len)
		tab->len += write(1, "0", 1);
	if (len > 0)
		ft_putstr_fd(str, 1);
	tab->len += len;
}

static void	uint_printleft(char *str, int len, t_flags *tab)
{
	int	i;
	int	area;
	int	prec_pad;

	i = -1;
	prec_pad = precision_control(len, tab);
	area = tab->width - (prec_pad + len);
	if (prec_pad > 0)
		ft_check_addflags(0, tab);
	while (++i < prec_pad)
		tab->len += write(1, "0", 1);
	if (!prec_pad)
		ft_check_addflags(0, tab);
	if (len > 0)
		ft_putstr_fd(str, 1);
	tab->len += len;
	i = -1;
	while (++i < area)
		tab->len += write(1, " ", 1);
}

static void	uint_wdth(char *str, int len, t_flags *tab)
{
	int	i;
	int	area;
	int	prec_pad;

	i = -1;
	prec_pad = precision_control(len, tab);
	area = tab->width - (prec_pad + len);
	while (++i < area)
		tab->len += write(1, " ", 1);
	i = -1;
	if (prec_pad > 0)
		ft_check_addflags(0, tab);
	i = -1;
	while (++i < prec_pad)
		tab->len += write(1, "0", 1);
	if (!prec_pad)
		ft_check_addflags(0, tab);
	if (len > 0)
		ft_putstr_fd(str, 1);
	tab->len += len;
}

static void	uint_flags(char *str, int len, t_flags *tab)
{
	if (tab->zero && !tab->check_precision)
		uint_pad_zero(str, len, tab);
	else if (tab->minus)
		uint_printleft(str, len, tab);
	else
		uint_wdth(str, len, tab);
}

void	ft_print_uint(t_flags *tab)
{
	unsigned int	num;
	int				len;
	char			*str;

	num = va_arg(tab->ap, unsigned int);
	str = ft_itoa(num);
	if (num == 0 && !tab->precision && tab->check_precision)
		len = 0;
	else
		len = (int)ft_strlen(str);
	if (tab->plus || tab->space)
		tab->width--;
	uint_flags(str, len, tab);
	free(str);
}
