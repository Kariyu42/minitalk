/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:20:23 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/10 20:56:53 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dst;

	if ((!dst || !src) && dstsize == 0)
		return (0);
	i = 0;
	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	if (dstsize <= len_dst)
		return (dstsize + len_src);
	while (src[i] && i < (dstsize - 1 - len_dst))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[(len_dst + i)] = '\0';
	return (len_src + len_dst);
}

/*int	main(void)
{
	char dst[20] = "Bonjour.";
	char src[] = "les.gens";
	//printf("%lu\n", strlcat(dst, src, 20));
	//printf("dst : %s\n", dst);
	printf("%lu\n", ft_strlcat(dst, src, 8));
	printf("dst : %s", dst);
	return (0);
}*/