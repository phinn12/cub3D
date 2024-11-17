/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:52:39 by ibkocak           #+#    #+#             */
/*   Updated: 2023/10/21 17:01:56 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*dest;
	char	*sorc;
	size_t	a;

	a = 0;
	dest = dst;
	sorc = (char *)src;
	if (dstsize > 0)
	{
		while (sorc[a] && a < dstsize - 1)
		{
			dest[a] = sorc[a];
			a++;
		}
		dest[a] = '\0';
	}
	a = 0;
	while (src[a])
	{
		a++;
	}
	return (a);
}
