/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:50:41 by ibkocak           #+#    #+#             */
/*   Updated: 2023/10/21 17:00:59 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	slen;

	slen = ft_strlen(s);
	while (slen >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		slen--;
		s++;
	}
	return (NULL);
}
