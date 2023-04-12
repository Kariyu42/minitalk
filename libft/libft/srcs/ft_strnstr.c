/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:03:14 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/10 20:56:53 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	if (len == 0)
		return (0);
	while (*(char *)(s1 + i) && (i < len))
	{
		j = 0;
		while (*(char *)(s1 + i + j) == *(char *)(s2 + j) && (i + j) < len)
		{
			j++;
			if (*(char *)(s2 + j) == '\0')
			{
				return ((char *)(s1 + i));
			}
		}
		i++;
	}
	return (NULL);
}
