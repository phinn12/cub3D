/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:48:07 by ibkocak           #+#    #+#             */
/*   Updated: 2023/10/21 17:00:23 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		*a;
	size_t		t;

	a = (char *)s;
	t = 0;
	while (t < n)
	{
		if (a[t] == (char)c)
		{
			return (a + t);
		}
		t++;
	}
	return (NULL);
}
