/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:15:06 by ibkocak           #+#    #+#             */
/*   Updated: 2023/10/21 17:11:13 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	result_len;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result_len = len1 + len2 + 1;
	result = (char *)malloc(result_len);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, len1 + 1);
	ft_strlcat(result, s2, result_len);
	return (result);
}
