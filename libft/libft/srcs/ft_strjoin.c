/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:59:13 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/12 10:10:09 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	*ft_strcat(char *dest, const char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	full_tab;

	if (!s1 || !s2)
		return (0);
	full_tab = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (full_tab + 1));
	if (!str)
		return (0);
	str[0] = '\0';
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	return (str);
}

/*int	main(void)
{
	char s1[] = "Bonjour";
	char s2[] = "Toi, comment ca va???";
	printf("%s", ft_strjoin(s1, s2));
	return (0);
}*/

/*char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		i;
	int		full_tab;

	i = 0;
	full_tab = 0;
	while (i < size)
		full_tab += ft_strlen(strs[i++]);
	if (size)
		full_tab += (ft_strlen(sep)) * (size - 1);
	tab = malloc(sizeof(char) * (full_tab + 1));
	tab[0] = '\0';
	if (tab == 0)
		return (0);
	if (size == 0)
		return (tab);
	i = -1;
	while (++i < size)
	{
		tab = ft_strcat(tab, strs[i]);
		if (i != size - 1)
			tab = ft_strcat(tab, sep);
	}
	tab[full_tab] = '\0';
	return (tab);
}*/