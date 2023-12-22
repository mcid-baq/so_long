/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:05:30 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/05/16 12:11:20 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long p, char *hex)
{
	int	length;

	length = 0;
	if (p == 0)
		return (ft_printchar('0'));
	if (p > 15)
	{
		length += ft_printhex(p / 16, hex);
		length += ft_printhex(p % 16, hex);
	}
	else
		length += ft_printchar(hex[p % 16]);
	return (length);
}
