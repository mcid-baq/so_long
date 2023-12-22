/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:10 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/12/22 13:48:46 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
