/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:06:18 by ibkocak           #+#    #+#             */
/*   Updated: 2024/10/15 17:17:44 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_reader(int fd, char *str)
{
	char	*dst;
	int		i;

	i = 1;
	dst = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (!ft_strchar(str, '\n') && i != 0)
	{
		i = read(fd, dst, BUFFER_SIZE);
		if (i == -1)
		{
			free (str);
			free (dst);
			return (NULL);
		}
		dst[i] = '\0';
		str = ft_strjoin(str, dst);
	}
	free (dst);
	return (str);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (str[i] == 0)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*ft_get_lef(char *str)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	i++;
	res = malloc(sizeof(char) * (ft_strlenx(str) - i + 1));
	if (!res)
		return (NULL);
	j = 0;
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	free (str);
	return (res);
}

char	*get_next_line(int fd)
{
	char			*str;
	static char		*dst;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	dst = ft_reader(fd, dst);
	if (!dst)
		return (NULL);
	str = ft_get_line(dst);
	dst = ft_get_lef(dst);
	return (str);
}
