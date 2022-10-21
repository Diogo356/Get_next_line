/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:47:44 by dbelarmi          #+#    #+#             */
/*   Updated: 2022/10/21 16:26:44 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *left_str)
{
	char *str;
	int count_byte;

	str = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if(!str)
	{
		free(str);
		return(NULL);
	}
	count_byte = 1;
	while (!ft_strchr(str, '\n') && count_byte != 0)
	{
		count_byte = read(fd, str, BUFFER_SIZE);
		if(count_byte == -1)
		{
			free(str);
			return(NULL);
		}
		left_str = ft_strjoin(left_str, str);
	}
	free(str);
	return(left_str);	
}

char	*find_break_line(char *left_str)
{
	int			i;
	int         s;
	char		*str;

	i = 0;
	if (!left_str)
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)ft_calloc(sizeof(char), (i + 2));
	if (!str)
		return (NULL);
	s = 0;
	while (left_str[s] && left_str[s] != '\n')
	{
		str[s] = left_str[s];
		s++;
	}
	if (left_str[s] == '\n')
	{
		str[s] = left_str[s];
		s++;
	}
	return (str);
}

char	*new_position(char *left_str)//função para armazenar a nova posição;
{
	int			s;
	int			i;
	char		*str;

	i = 0;
	s = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (left_str[i] == '\0')
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)ft_calloc(sizeof(char), (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (left_str[i])
		str[s++] = left_str[i++];
	free(left_str);
	return (str);
}
char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0) 
		return (NULL);
	left_str = read_line(fd, left_str);
	if (!left_str)
		return (NULL);
	line = find_break_line(left_str);
	left_str = new_position(left_str);
	if (line[0] == '\0')
	{
		free(left_str);
		free(line);
		return (NULL);
	}
	return (line);
}

int main(void)
{
	int fd;
	char *line;

	fd = open("texto.txt", O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}