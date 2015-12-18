/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udelorme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:36:25 by udelorme          #+#    #+#             */
/*   Updated: 2015/12/04 19:09:53 by udelorme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	guess_len(int nbr)
{
	int i;

	i = 1;
	while (nbr /= 10)
		i++;
	return (i);
}

static int	foo(int n, int *neg)
{
	if (n < 0)
	{
		n = -n;
		*neg = 1;
	}
	return (n);
}

char		*ft_itoa(int n)
{
	char	*ret;
	int		len;
	int		i;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	n = foo(n, &neg);
	len = guess_len(n) + neg;
	ret = ft_strnew(len);
	i = len;
	ret[len] = 0;
	while (--i >= 0)
		if (i == 0 && len != 1 && neg)
			ret[i] = '-';
		else
		{
			ret[i] = (n % 10) + 48;
			n /= 10;
		}
	return (ret);
}
