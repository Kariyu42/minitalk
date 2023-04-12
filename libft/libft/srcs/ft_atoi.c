/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 08:57:48 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/10 20:56:53 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] == '\f')
		|| (str[i] == '\n') || (str[i] == '\r')
		|| (str[i] == '\t') || (str[i] == '\v'))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && ft_isdigit(str[i]))
	{	
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

/*int	main(void)
{
	const char	str[] = "-+42";
	//const char	str1[] = "12346124bdw2";
	printf("Vrai Fonction: %d\n", atoi(str));
	printf("Ma fonction: %d\n", ft_atoi(str));
	return (0);
}
*/