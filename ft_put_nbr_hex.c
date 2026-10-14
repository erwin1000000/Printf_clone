/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:26:30 by yabyaa            #+#    #+#             */
/*   Updated: 2025/12/25 18:07:54 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_put_nbr_hex_help(size_t *hex, char *buff, char u_or_l, int *i)
{
	size_t	hold;
	char	*buffl;
	char	*buffu;

	buffl = "abcdef";
	buffu = "ABCDEF";
	while (*hex > 0)
	{
		hold = *hex % 16;
		*hex = *hex / 16;
		if (hold > 9)
		{
			if (u_or_l == 'l')
				buff[*i] = buffl[hold - 10];
			else
				buff[*i] = buffu[hold - 10];
		}
		else
			buff[*i] = hold + '0';
		--(*i);
	}
}

int	ft_put_nbr_hex(size_t hex, char u_or_l)
{
	char	buff[16];
	int		i;

	i = 15;
	if (hex == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	ft_put_nbr_hex_help(&hex, buff, u_or_l, &i);
	write(1, &buff[i + 1], (16 - (i + 1)));
	return (16 - (i + 1));
}
