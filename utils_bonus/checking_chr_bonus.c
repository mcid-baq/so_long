/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:54:37 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/04/15 12:43:50 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*Enemigos representados con la X*/

int	checking_chr_bonus(char *str)
{
	char	*aux;

	if (str == 0 || *str == 0)
		return (1);
	aux = ft_strchr("01CEPX", *str++);
	while (aux && *str)
		aux = ft_strchr("01CEPX", *str++);
	if (!aux)
		return (1);
	return (0);
}
