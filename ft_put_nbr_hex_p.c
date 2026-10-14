/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_hex_p.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 12:25:19 by yabyaa            #+#    #+#             */
/*   Updated: 2025/12/25 15:39:32 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_put_nbr_hex_p_help(size_t *hex, char *buff, char u_or_l, int *i)
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

int	ft_put_nbr_hex_p(size_t hex, char u_or_l)
{
	char	buff[18];
	int		i;

	i = 17;
	if (hex == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	ft_put_nbr_hex_p_help(&hex, buff, u_or_l, &i);
	buff[i] = 'x';
	buff[i - 1] = '0';
	write(1, &buff[i - 1], (18 - (i - 1)));
	return (18 - (i - 1));
}
