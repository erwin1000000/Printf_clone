/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:19:28 by yabyaa            #+#    #+#             */
/*   Updated: 2025/12/26 16:22:41 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_printf_help(int *len, int *i, char *fstr, va_list *args)
{
	if (fstr[*i] == '%')
		*len = *len + ft_putchar(fstr[*i]);
	else if (fstr[*i] == 'c')
		*len = *len + ft_putchar(va_arg(*args, int));
	else if (fstr[*i] == 's')
		*len = *len + ft_putstr(va_arg(*args, char *));
	else if (fstr[*i] == 'd' || fstr[*i] == 'i')
		*len = *len + ft_putnbr(va_arg(*args, int));
	else if (fstr[*i] == 'u')
		*len = *len + ft_putnbr_u(va_arg(*args, unsigned int));
	else if (fstr[*i] == 'p')
		*len = *len + ft_put_nbr_hex_p((size_t)va_arg(*args, void *), 'l');
	else if (fstr[*i] == 'x')
		*len = *len + ft_put_nbr_hex(va_arg(*args, unsigned int), 'l');
	else if (fstr[*i] == 'X')
		*len = *len + ft_put_nbr_hex(va_arg(*args, unsigned int), 'u');
}

int	ft_printf(const char *fstr, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, fstr);
	while (fstr[i])
	{
		while (fstr[i] != '%' && fstr[i])
		{
			len = len + ft_putchar(fstr[i]);
			++i;
		}
		if (fstr[i] == '%')
		{
			++i;
			if (!fstr[i])
				return (len);
			ft_printf_help(&len, &i, (char *)fstr, &args);
			++i;
		}
	}
	va_end(args);
	return (len);
}
