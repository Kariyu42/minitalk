/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_padd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:42:48 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/13 11:09:15 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"

void	hexa_zero_padd(unsigned int num, int len, t_flags *tab, char *base)
{
	int	i;

	i = -1;
	ft_hexa_flags(num, tab);
	while (++i < tab->width - len)
		tab->len += write(1, "0", 1);
	if (len > 0)
		ft_base_convert(num, tab, base);
}

void	hexa_left_wdth(unsigned int num, int len, t_flags *tab, char *base)
{
	int	i;
	int	area;
	int	prec_pad;

	i = -1;
	prec_pad = precision_control(len, tab);
	area = tab->width - (prec_pad + len);
	if (prec_pad > 0)
		ft_hexa_flags(num, tab);
	while (++i < prec_pad)
		tab->len += write(1, "0", 1);
	if (!prec_pad)
		ft_hexa_flags(num, tab);
	if (len > 0)
		ft_base_convert(num, tab, base);
	i = -1;
	while (++i < area)
		tab->len += write(1, " ", 1);
}

void	hexa_wdth(unsigned int num, int len, t_flags *tab, char *base)
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
		ft_hexa_flags(num, tab);
	i = -1;
	while (++i < prec_pad)
		tab->len += write(1, "0", 1);
	if (!prec_pad)
		ft_hexa_flags(num, tab);
	if (len > 0)
		ft_base_convert(num, tab, base);
}
