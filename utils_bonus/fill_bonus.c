/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:15:50 by mcid-baq          #+#    #+#             */
/*   Updated: 2024/04/16 17:03:22 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	fill_bonus(t_list *list, int x, int y)
{
	if (x < 0 || y < 0 || x >= list->llines || y >= list->nlines
		|| !ft_strchr("0PCEX", list->sm[y][x]))
		return ;
	if (list->sm[y][x] == '0')
		list->sm[y][x] = 'A';
	else if (list->sm[y][x] == 'P')
		list->sm[y][x] = 'S';
	else if (list->sm[y][x] == 'C')
		list->sm[y][x] = 'D';
	else if (list->sm[y][x] == 'E')
		list->sm[y][x] = 'F';
	else if (list->sm[y][x] == 'X')
		list->sm[y][x] = 'Y';
	fill_bonus(list, x - 1, y);
	fill_bonus(list, x + 1, y);
	fill_bonus(list, x, y - 1);
	fill_bonus(list, x, y + 1);
}

void	back_fill(t_list *list, int y, int x)
{
	if (list->sm[y][x] == 'C' || list->sm[y][x] == 'E')
		return ;
	else if (list->sm[y][x] == 'A')
		list->sm[y][x] = '0';
	else if (list->sm[y][x] == 'S')
		list->sm[y][x] = 'P';
	else if (list->sm[y][x] == 'D')
		list->sm[y][x] = 'C';
	else if (list->sm[y][x] == 'F')
		list->sm[y][x] = 'E';
	else if (list->sm[y][x] == 'Y')
		list->sm[y][x] = 'X';
}

int	fill_works_bonus(t_list *list)
{
	int	y;
	int	x;

	y = 0;
	while (list->sm[y])
	{
		x = 0;
		while (list->sm[y][x])
		{
			back_fill(list, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
