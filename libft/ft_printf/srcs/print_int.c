/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 23:33:08 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/13 11:09:19 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

static void	add_zero_padd(char *tmp, int len, int sign, t_flags *tab)
{
	int	i;

	i = -1;
	ft_check_addflags(sign, tab);
	if (tab->width > len)
		while (++i < tab->width - len)
			tab->len += write(1, "0", 1);
	if (len > 0)
		ft_putstr_fd(tmp, 1);
	tab->len += len;
}

static void	print_left_di(char *tmp, int len, int sign, t_flags *tab)
{
	int	i;
	int	area;
	int	prec_pad;

	i = -1;
	prec_pad = precision_control(len, tab);
	area = tab->width - (prec_pad + len);
	if (prec_pad > 0)
		ft_check_addflags(sign, tab);
	while (++i < prec_pad)
		tab->len += write(1, "0", 1);
	if (!prec_pad)
		ft_check_addflags(sign, tab);
	if (len > 0)
		ft_putstr_fd(tmp, 1);
	tab->len += len;
	i = -1;
	while (++i < area)
		tab->len += write(1, " ", 1);
}

static void	print_wdth_di(char *tmp, int len, int sign, t_flags *tab)
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
		ft_check_addflags(sign, tab);
	i = -1;
	while (++i < prec_pad)
		tab->len += write(1, "0", 1);
	if (!prec_pad)
		ft_check_addflags(sign, tab);
	if (len > 0)
		ft_putstr_fd(tmp, 1);
	tab->len += len;
}

static void	num_flags(char *tmp, int len, int sign, t_flags *tab)
{
	if (tab->zero && !tab->check_precision)
		add_zero_padd(tmp, len, sign, tab);
	else if (tab->minus)
		print_left_di(tmp, len, sign, tab);
	else
		print_wdth_di(tmp, len, sign, tab);
}

void	ft_print_di(t_flags *tab)
{
	long long	num;
	int			len;
	int			sign;
	char		*tmp;

	sign = 0;
	num = va_arg(tab->ap, int);
	if (num < 0)
	{
		sign = 1;
		num *= -1;
	}
	tmp = ft_itoa(num);
	if (num == 0 && !tab->precision && tab->check_precision)
		len = 0;
	else
		len = (int)ft_strlen(tmp);
	if (sign || tab->plus || tab->space)
		tab->width--;
	num_flags(tmp, len, sign, tab);
	free(tmp);
}
