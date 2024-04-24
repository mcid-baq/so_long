/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:10 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/04/12 19:35:42 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	close_and_print(int m, char *p, t_list *list)
{
	close(m);
	if (p)
		free(p);
	print_error("Error ", list);
}

void	print_error(char *error, t_list *list)
{
	ft_printf("%s\n", error);
	free_error(list);
}
