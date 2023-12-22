/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:10:36 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/05/16 13:09:24 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nb)
{
	int	length;

	length = 0;
	if (nb == -2147483648)
	{
		ft_printstr("-2147483648");
		return (11);
	}
	else if (nb < 0)
	{
		length += ft_printchar('-');
		length += ft_printnbr(-nb);
	}
	else if (nb > 9)
	{
		length += ft_printnbr(nb / 10);
		length += ft_printnbr(nb % 10);
	}
	else
		length += ft_printchar(nb + 48);
	return (length);
}
