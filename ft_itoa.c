/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 17:19:18 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/18 20:03:21 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(int n);
static long	f_pw(long nb, int power);
static char	*ft_num_parse(int l, int neg, int n, long n2);

char	*ft_itoa(int n)
{
	char	*p;
	int		l;
	int		neg;
	long	n2;

	neg = 0;
	l = ft_num_len(n);
	n2 = n;
	if (n < 0 && l == 10 && n == -2147483648)
		return (p = ft_strdup("-2147483648"));
	else if (n < 0)
	{	
		n2 = n * -1;
		neg = 1;
	}
	else if (n == 0)
		return (p = ft_strdup("0"));
	return (p = ft_num_parse(l, neg, n, n2));
}

static char	*ft_num_parse(int l, int neg, int n, long n2)
{
	char	*p;
	int		i;

	i = -1;
	p = malloc(sizeof(char) * (l + neg + 1));
	if (!p)
		return (0);
	while (++i < (l + neg))
		p[i + neg] = (n2 % f_pw(10, l - i)) / f_pw(10, l - i - 1) + '0';
	if (n < 0)
		p[0] = '-';
	p[i] = '\0';
	return (p);
}

static int	ft_num_len(int n)
{
	int	i;

	i = 1;
	if (n != 0)
	{
		return (i + ft_num_len(n / 10));
		i++;
	}
	else
		return (0);
}

static long	f_pw(long nb, int power)
{
	if (power <= 0)
		return (1);
	else if (power > 0)
		return (nb * f_pw(nb, power - 1));
	return (0);
}
