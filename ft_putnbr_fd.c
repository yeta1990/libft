/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albgarci <albgarci@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 21:04:01 by albgarci          #+#    #+#             */
/*   Updated: 2021/09/22 16:29:31 by albgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_printer(int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
		recursive_printer(n, fd);
}

static void	recursive_printer(int n, int fd)
{
	char			c;
	unsigned int	number;

	number = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		recursive_printer(number * -1 / 10, fd);
		c = (number * -1 % 10) + 48;
		ft_putchar_fd(c, fd);
	}
	if (n > 0)
	{
		recursive_printer(number / 10, fd);
		c = (number % 10) + 48;
		ft_putchar_fd(c, fd);
	}
}
