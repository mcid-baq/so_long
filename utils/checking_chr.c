/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:37 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/12/22 13:49:20 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checking_chr(char *str)
{
	char	*aux;

	if (str == 0 || *str == 0)
		return (1);
	aux = ft_strchr("01CEP", *str++);
	while (aux && *str)
		aux = ft_strchr("01CEP", *str++);
	if (!aux)
		return (1);
	return (0);
}
