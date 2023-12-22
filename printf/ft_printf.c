/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:19:12 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/05/18 11:55:23 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_variable(va_list args, const char str)
{
	int		length;
	char	*hex;

	length = 0;
	hex = "0123456789abcdef";
	if (str == 'c')
		length += ft_printchar(va_arg(args, int));
	else if (str == 's')
		length += ft_printstr(va_arg(args, char *));
	else if (str == 'p')
	{
		length += ft_printstr("0x");
		length += ft_printhex(va_arg(args, unsigned long), hex);
	}
	else if (str == 'd' || str == 'i')
		length += ft_printnbr(va_arg(args, int));
	else if (str == 'u')
		length += ft_printunsignbr(va_arg(args, unsigned int));
	else if (str == 'x')
		length += ft_printhex(va_arg(args, unsigned int), hex);
	else if (str == 'X')
		length += ft_printhex(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (str == '%')
		length += ft_printchar('%');
	return (length);
}

int	ft_printf(char const *str, ...)
{
	int		x;
	va_list	args;
	int		length;

	length = 0;
	x = 0;
	va_start(args, str);
	while (str[x])
	{
		if (str[x] == '%')
		{
			x++;
			length += ft_variable(args, str[x]);
		}
		else
		{
			length += ft_printchar(str[x]);
		}
		x++;
	}
	va_end(args);
	return (length);
}
