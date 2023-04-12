/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:22:00 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/10 20:56:53 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = -1;
	if (!c || c == 1024)
		return ((char *)str + ft_strlen(str));
	while (str[++i] && (char)c)
		if (str[i] == (char)c)
			return ((char *)str + i);
	return (0);
}

/*int	main(void)
{
	char s1[] = "Bonjour a tout le monde";
	int	c = 'e';
	printf("Ma fonction : %s\n", ft_strchr("\0", '\0'));
	printf("Vrai fonction : %s\n", strchr("\0", '\0'));
	return (0);
}*/