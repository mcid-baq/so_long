/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcid-baq <mcidbaquerizo@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:14:49 by mcid-baq          #+#    #+#             */
/*   Updated: 2023/12/21 12:27:01 by mcid-baq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_get_lines(int fd, char *str)
{
	char	*temp;
	int		temp_lenght;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (temp == NULL)
		return (NULL);
	temp_lenght = -1;
	while (ft_strchr_gnl(str, '\n') == NULL && temp_lenght != 0)
	{
		temp_lenght = read(fd, temp, BUFFER_SIZE);
		if (temp_lenght < 0)
		{
			free(temp);
			return (NULL);
		}
		temp[temp_lenght] = '\0';
		str = ft_strjoin_gnl(str, temp);
	}
	free(temp);
	return (str);
}

char	*ft_actual_line(char *str, char *line)
{
	int	count;

	count = 0;
	if (str[count] == '\0')
		return (NULL);
	while (str[count] != '\n' && str[count] != '\0')
		count++;
	if (str[count] == '\n')
		line = malloc((count + 2) * sizeof(char));
	else if (str[count] == '\0')
		line = malloc((count + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	count = -1;
	while (str[++count] != '\n' && str[count] != '\0')
		line[count] = str[count];
	if (str[count] == '\n')
		line[count++] = '\n';
	line[count] = '\0';
	return (line);
}

char	*ft_get_rest(char *str)
{
	size_t	count;
	size_t	str_length;
	char	*rest_str;
	size_t	rest_count;

	count = 0;
	while (str[count] != '\0' && str[count] != '\n')
		count++;
	if (str[count] == '\0')
	{
		free(str);
		return (NULL);
	}
	str_length = ft_strlen_gnl(str);
	rest_str = malloc((str_length - count) * sizeof(char));
	if (rest_str == NULL)
		return (NULL);
	count++;
	rest_count = 0;
	while (str[count] != '\0')
		rest_str[rest_count++] = str[count++];
	rest_str[rest_count] = '\0';
	free(str);
	return (rest_str);
}

char	*get_next_line(int fd)
{
	static char	*next_line[4096];
	char		*actual_line;
	char		*next_string;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_string = ft_get_lines(fd, next_line[fd]);
	if (next_string == NULL)
	{
		if (next_line[fd])
		{
			free(next_line[fd]);
			next_line[fd] = NULL;
		}
		return (NULL);
	}
	next_line[fd] = next_string;
	actual_line = NULL;
	actual_line = ft_actual_line(next_line[fd], actual_line);
	next_line[fd] = ft_get_rest(next_line[fd]);
	return (actual_line);
}
