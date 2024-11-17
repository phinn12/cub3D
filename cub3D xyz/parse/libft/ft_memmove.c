/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:49:46 by ibkocak           #+#    #+#             */
/*   Updated: 2023/10/21 17:00:47 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*sorc;

	dest = dst;
	sorc = src;
	if (len == 0 || dst == src)
		return (dest);
	if (dst < src)
	{
		while (len > 0)
		{
			*dest++ = *sorc++;
			len--;
		}
	}
	if (dst > src)
	{
		while (len > 0)
		{
			len--;
			dest[len] = sorc[len];
		}
	}
	return (dst);
}
