/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:18:36 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/05/16 13:22:21 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *str)
{
	int	x;

	x = 0;
	if (str == 0)
		return (ft_printstr("(null)"));
	while (str[x] != '\0')
	{
		ft_printchar(str[x]);
		x++;
	}
	return (x);
}
