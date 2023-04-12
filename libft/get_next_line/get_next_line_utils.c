/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:29:44 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/12 10:14:01 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str || !c)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == ((char)c))
			return ((char *)str + i);
		i++;
	}
	return (0);
}

void	ft_bzero(void *str, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((char *) str)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size && (((size_t) - 1) / size) < count)
		return (0);
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, size * count);
	return (ptr);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	if (!s1)
		s1 = ft_calloc(1, 1);
	i = 0;
	len = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	result = ft_calloc(len + 1, sizeof(char));
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	return (result);
}
