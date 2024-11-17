/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:49:14 by ibkocak           #+#    #+#             */
/*   Updated: 2023/10/21 17:00:43 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	a;

	a = 0;
	if (dst == NULL && src == NULL)
		return (0);
	while (a < n)
	{
		((char *)dst)[a] = ((char *)src)[a];
		a++;
	}
	return (dst);
}
