/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:04:33 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/13 11:07:34 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* libft header */
# include "libft.h"
/* libraries */
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

/* struct */
typedef struct s_flags
{
	va_list	ap;
	int		len;
	int		zero;
	int		plus;
	int		hash;
	int		width;
	int		minus;
	int		space;
	int		precision;
	int		check_precision;
}	t_flags;

/* prototype */
int		ft_printf(const char *format, ...);

/* width & precision */
void	ft_get_width(const char *format, t_flags *tab, int i);
void	ft_get_precision(const char *format, t_flags *tab, int i);

/* print c */
void	ft_print_c(t_flags *tab);
void	ft_print_percent(t_flags *tab);
/* print s */
void	ft_print_s(t_flags *tab);
/* print p */
void	ft_print_p(t_flags *tab);
void	ft_base_convert(unsigned long num, t_flags *tab, char *base);
/* print d & i + utils */
void	ft_print_di(t_flags *tab);
void	ft_check_addflags(int sign, t_flags *tab);
/* print u */
void	ft_print_uint(t_flags *tab);
/* print x & X*/
void	ft_print_hexa(t_flags *tab, char *base);
void	hexa_zero_padd(unsigned int num, int len, t_flags *tab, char *base);
void	hexa_left_wdth(unsigned int num, int len, t_flags *tab, char *base);
void	hexa_wdth(unsigned int num, int len, t_flags *tab, char *base);
void	ft_hexa_flags(unsigned int num, t_flags *tab);
/* others */
int		ft_locate_format(char *s1, int c);
int		precision_control(int len, t_flags *tab);

#endif
