/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:19:51 by ibkocak           #+#    #+#             */
/*   Updated: 2024/10/15 17:45:36 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlenx(const char *str)
{
    int length = 0;
    while (str[length])
        length++;
    return length;
}



char	*ft_strchar(char *str, char c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (str + i);
		i++;
	}
	return (0);
}

char *ft_strjoin(const char *s1, const char *s2)
{
    int i = 0;
    int j = 0;
    char *res;

    if (!s1)
        s1 = "";
    if (!s2)
        return (NULL);

    res = malloc(sizeof(char) * (ft_strlenx(s1) + ft_strlenx(s2) + 1));
    if (!res)
        return (NULL);

    while (s1[i])
    {
        res[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        res[i] = s2[j];
        i++;
        j++;
    }
    res[i] = '\0';

    return (res);
}

