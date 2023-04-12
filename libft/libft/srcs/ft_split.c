/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:35:43 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/10 20:56:53 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	ft_lenword(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	int			j;
	int			count;
	size_t		start;
	char		**str;

	if (!s)
		return (0);
	i = 0;
	count = ft_lenword(s, c);
	str = malloc(sizeof(char *) * (count + 1));
	if (!str)
		return (0);
	j = -1;
	while (++j < count)
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		str[j] = ft_substr(s, start, i - start);
	}
	str[j] = NULL;
	return (str);
}

/*int	main(void)
{
	int i;
	char	str[] = "     split   this for   me !  ";
	char c = ' ';
	
	char **s1 = ft_split(str, c);
	while (s1[i])
	{
		printf("%s\n", s1[i]);
		i++;
	}
	return (0);
}*/
