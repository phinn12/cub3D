/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 13:57:28 by ibkocak           #+#    #+#             */
/*   Updated: 2023/10/16 18:00:24 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	dest;
	size_t	sorc;

	dest = ft_strlen(dst);
	sorc = ft_strlen((char *)src);
	a = 0;
	if (dstsize <= dest)
		return (sorc + dstsize);
	while (src[a] && dest + a + 1 < dstsize)
	{
		dst[dest + a] = src[a];
		a++;
	}
	dst[dest + a] = '\0';
	return (dest + sorc);
}
