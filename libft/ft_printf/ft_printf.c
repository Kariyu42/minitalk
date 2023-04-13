/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 10:30:21 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/13 11:07:58 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_flags	*ft_declare_tab(t_flags *tab)
{
	tab->len = 0;
	tab->minus = 0;
	tab->plus = 0;
	tab->hash = 0;
	tab->zero = 0;
	tab->space = 0;
	tab->width = 0;
	tab->precision = 0;
	tab->check_precision = 0;
	return (tab);
}

int	ft_locate_format(char *s1, int c)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static void	ft_convert_format(char c, t_flags *tab)
{
	if (c == 'c')
		ft_print_c(tab);
	else if (c == 's')
		ft_print_s(tab);
	else if (c == 'p')
		ft_print_p(tab);
	else if (c == 'd' || c == 'i')
		ft_print_di(tab);
	else if (c == 'u')
		ft_print_uint(tab);
	else if (c == 'x')
	{
		if (tab->hash)
			tab->hash = 2;
		ft_print_hexa(tab, "0123456789abcdef");
	}
	else if (c == 'X')
	{
		if (tab->hash)
			tab->hash = 3;
		ft_print_hexa(tab, "0123456789ABCDEF");
	}
	else if (c == '%')
		ft_print_percent(tab);
}

static int	ft_parse_flag(t_flags *tab, const char *format, int i)
{
	ft_get_width(format, tab, i);
	ft_get_precision(format, tab, i);
	tab->hash = 0;
	tab->plus = 0;
	tab->space = 0;
	while (format[i] && !ft_locate_format("cspdiuxX%", format[i]))
	{
		if (format[i] == ' ')
			tab->space = 1;
		else if (format[i] == '+')
			tab->plus = 1;
		else if (format[i] == '#')
			tab->hash = 1;
		i++;
	}
	if (format[i] && ft_locate_format("cspdiuxX%", format[i]))
		ft_convert_format(format[i], tab);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	t_flags	*tab;

	i = 0;
	len = 0;
	tab = malloc(sizeof(t_flags));
	if (!tab)
		return (0);
	ft_declare_tab(tab);
	va_start(tab->ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			i = ft_parse_flag(tab, format, i + 1);
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(tab->ap);
	len += tab->len;
	free(tab);
	return (len);
}
