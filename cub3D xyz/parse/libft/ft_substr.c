/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:24:21 by ibkocak           #+#    #+#             */
/*   Updated: 2023/10/21 17:02:20 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*f;

	i = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= i)
		return (ft_strdup(""));
	if (len > i - start)
		len = i - start;
	f = (char *)malloc(len + 1);
	if (!f)
		return (NULL);
	j = 0;
	while (j < len)
	{
		f[j] = s[start];
		j++;
		start++;
	}
	f[j] = '\0';
	return (f);
}
