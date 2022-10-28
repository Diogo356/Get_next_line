/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:47:44 by dbelarmi          #+#    #+#             */
/*   Updated: 2022/10/28 20:53:53 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(int fd, char *str)
{
	char	*buffer;
	int		count_byte;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	count_byte = 1;
	while (!ft_strchr(str, '\n') && count_byte != 0)
	{
		count_byte = read(fd, buffer, BUFFER_SIZE);
		if (count_byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[count_byte] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free(buffer);
	return (str);
}

static char	*find_break_line(char *str)
{
	int			i;
	char		*new;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new = (char *) malloc (sizeof(char) * (i + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char	*new_position(char *str)
{
	int			s;
	int			i;
	char		*new;

	i = 0;
	s = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new)
		return (NULL);
	i++;
	while (str[i])
		new[s++] = str[i++];
	new[s] = '\0';
	free(str);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str;

	line = NULL;
	if (fd >= FD_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	line = find_break_line(str);
	str = new_position(str);
	if (line[0] == '\0')
	{
		free(str);
		free(line);
		return (NULL);
	}
	return (line);
}
//abc