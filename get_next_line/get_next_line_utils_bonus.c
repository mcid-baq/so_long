/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:14:44 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/12/21 17:37:29 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_gnl(char *x)
{
	size_t	count;

	count = 0;
	while (x[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin_gnl(char *next_line, char *temp)
{
	char	*dest;
	size_t	next_line_lenght;
	size_t	temp_lenght;
	int		count;

	if (next_line == NULL)
	{
		next_line = malloc(sizeof(char));
		next_line[0] = '\0';
	}
	next_line_lenght = ft_strlen_gnl(next_line);
	temp_lenght = ft_strlen_gnl(temp);
	dest = malloc((next_line_lenght + temp_lenght + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	count = -1;
	while (next_line[++count] != '\0')
		dest[count] = next_line[count];
	count = -1;
	while (temp[++count] != '\0')
		dest[count + next_line_lenght] = temp[count];
	dest[count + next_line_lenght] = '\0';
	free(next_line);
	return (dest);
}

char	*ft_strchr_gnl(char *x, int y)
{
	int	count;

	if (x == NULL)
		return (NULL);
	count = -1;
	while (x[++count] != '\0')
		if (x[count] == (char)y)
			return (&x[count]);
	if ((char)y == '\0')
		return (&x[count]);
	return (NULL);
}
