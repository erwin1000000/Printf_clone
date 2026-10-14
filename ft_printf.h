/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabyaa <yabyaa@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:23:52 by yabyaa            #+#    #+#             */
/*   Updated: 2025/12/25 19:14:12 by yabyaa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int	ft_put_nbr_hex(size_t hex, char u_or_l);
int	ft_putnbr_u(unsigned int n);
int	ft_put_nbr_hex_p(size_t hex, char u_or_l);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_printf(const char *fstr, ...);

#endif
