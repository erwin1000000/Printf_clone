/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 17:09:26 by yabyaa            #+#    #+#             */
/*   Updated: 2025/12/25 18:09:51 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	pn(unsigned int n, char *buffer)
{
	int	j;
	int	i;

	i = 0;
	j = 10;
	while (n > 0)
	{
		buffer[j] = (n % 10) + '0';
		n = n / 10;
		--j;
		++i;
	}
	++j;
	write(1, &buffer[j], i);
	return (i);
}

int	ft_putnbr_u(unsigned int n)
{
	char	buffer[11];

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		return (pn(n, buffer));
}
