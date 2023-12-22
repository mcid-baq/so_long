/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:15:50 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/12/22 13:41:43 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	fill(t_list *list, int x, int y)
{
	if (x < 0 || y < 0 || x >= list->llines || y >= list->nlines
		|| !ft_strchr("0PCE", list->sm[y][x]))
		return ;
	if (list->sm[y][x] == '0')
		list->sm[y][x] = 'A';
	else if (list->sm[y][x] == 'P')
		list->sm[y][x] = 'S';
	else if (list->sm[y][x] == 'C')
		list->sm[y][x] = 'D';
	else if (list->sm[y][x] == 'E')
		list->sm[y][x] = 'F';
	fill(list, x - 1, y);
	fill(list, x + 1, y);
	fill(list, x, y - 1);
	fill(list, x, y + 1);
}

int	fill_works(t_list *list)
{
	int	y;
	int	x;

	y = 0;
	while (list->sm[y])
	{
		x = 0;
		while (list->sm[y][x])
		{
			if (list->sm[y][x] == 'C' || list->sm[y][x] == 'E')
				return (1);
			else if (list->sm[y][x] == 'A')
				list->sm[y][x] = '0';
			else if (list->sm[y][x] == 'S')
				list->sm[y][x] = '0';
			else if (list->sm[y][x] == 'D')
				list->sm[y][x] = 'C';
			else if (list->sm[y][x] == 'F')
				list->sm[y][x] = 'E';
			x++;
		}
		y++;
	}
	return (0);
}
