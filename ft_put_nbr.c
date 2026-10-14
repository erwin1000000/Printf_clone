/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:59:25 by yabyaa            #+#    #+#             */
/*   Updated: 2025/12/25 19:01:12 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	pn(int n, char *buffer, int s, int i)
{
	int	j;

	j = 10;
	if (n < 0)
	{
		s = s * -1;
		n = n * -1;
	}
	while (n > 0)
	{
		buffer[j] = (n % 10) + '0';
		n = n / 10;
		--j;
		++i;
	}
	if (s == -1)
	{
		buffer[j] = '-';
		++i;
	}
	else
		++j;
	write(1, &buffer[j], i);
	return (i);
}

int	ft_putnbr(int n)
{
	char	buffer[11];
	int		s;

	s = 1;
	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}	
	else
		return (pn(n, buffer, s, 0));
}
