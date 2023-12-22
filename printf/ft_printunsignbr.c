/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsignbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:48:22 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/05/18 11:59:39 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printunsignbr(unsigned int nb)
{
	int	length;

	length = 0;
	if (nb < 0)
	{
		length += ft_printchar('-');
		nb = -nb;
	}
	else if (nb > 9)
	{
		length += ft_printunsignbr(nb / 10);
		length += ft_printunsignbr(nb % 10);
	}
	else
		length += ft_printchar(nb + 48);
	return (length);
}
