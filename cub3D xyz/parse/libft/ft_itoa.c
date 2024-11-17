/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibkocak < ibkocak@student.42istanbul.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:05:43 by ibkocak           #+#    #+#             */
/*   Updated: 2023/10/21 17:52:14 by ibkocak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(long n)
{
	int	a;

	a = 0;
	if (n == 0)
		a = 1;
	if (n < 0)
	{
		n = -n;
		a++;
		while (n > 0)
		{
			a++;
			n = n / 10;
		}
	}
	while (n > 0)
	{
		a++;
		n = n / 10;
	}
	return (a);
}

char	*ft_itoa(int n)
{
	int		len;
	long	a;
	char	*x;
	int		sign;

	a = n;
	len = ft_len(a);
	x = malloc(len + 1);
	sign = 1;
	if (!x)
		return (NULL);
	x[len] = '\0';
	if (a < 0)
	{
		a = -a;
		sign = -1;
	}
	while (--len >= 0)
	{
		x[len] = a % 10 + 48;
		a = a / 10;
	}
	if (sign == -1)
		x[0] = '-';
	return (x);
}
