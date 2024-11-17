/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:16:12 by ibkocak           #+#    #+#             */
/*   Updated: 2023/10/21 17:25:17 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	wordcount(char const *s, char c)
{
	int	i;
	int	b;

	i = 0;
	b = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			b++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (b);
}

static	char	**ft_split_words(char **res, const char *s, char c, int wordc)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i] && j < wordc)
	{
		len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			len++;
		}
		res[j] = ft_substr(s, i - len, len);
		j++;
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		wordc;

	wordc = wordcount(s, c);
	res = malloc(sizeof(char *) * (wordc + 1));
	if (!res)
		return (NULL);
	res = ft_split_words(res, s, c, wordc);
	return (res);
}
