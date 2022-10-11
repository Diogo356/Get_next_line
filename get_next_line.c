/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:47:44 by dbelarmi          #+#    #+#             */
/*   Updated: 2022/10/10 19:46:05 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//encontrar a primeira ocorrencia de um caractere na string;
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (0);
}

//leia linhas;
char	*read_line(int fd)
{
	char	str[];
	int		i;
	int		count_byte;

	i = 0;
	while (i <= BUFFER_SIZE)
		i++;
	str = (char *)ft_calloc(i + 1, sizeof(char));
	if (!str)
	{
		free(str);
		return (NULL);
	}
	count_byte = 1;
	while (!ft_strchr(str, '\n') && count_byte != 0)
	{
		count_byte = read(fd, str, i);
		if (count_byte == -1)
		{
			free(str);
			return (-1);
		}
		str[count_byte] = '\0';
		count_byte = ft_strjoin(count_byte, str);
	}
	free(str);
	return (count_byte);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		
}

// int main(void)
// {
// 	int file;
// 	char str[1000];

// 	ft_bzero(&str, 1000);
// 	file = open("texto.txt", O_RDONLY);
// 	if(file == -1)
// 	{
// 		printf("Não foi possivel abrir o arquivo.\n");
// 		exit(0);
// 	}
// 	while(read(file, str, BUFFER_SIZE) != 0)
// 	{
// 		printf("%s", str);
// 	}
// 	close(file);
// 	return(0);
// }
