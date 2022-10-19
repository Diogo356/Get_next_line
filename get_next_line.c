/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:47:44 by dbelarmi          #+#    #+#             */
/*   Updated: 2022/10/19 18:19:11 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s && c == '\0')
		return ((char *)(s + i));
	return (0);
}

//função para ler linha por linha do meu file descriptor 
char	*read_line(int fd, char *left_str)
{
	char *str;
	int count_byte;
	
	//alloca a memoria nescessaria com o \0 no final;
	str = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);

	//verifica se a alocação correu bem;
	if(!str)
	{
		free(str);
		return(NULL);
	}
	
	//meu contador começa em 1 por que não pode ser zero;
	count_byte = 1;

	//loop que verifica o \n na string e se o meu contador é diferente de zero;
	while (!ft_strchr(str, '\n') && count_byte != 0)
	{
		//meu contador recebe o valor de retorno read;
		count_byte = read(fd, str, BUFFER_SIZE);

		//verifica se o read correu bem;
		if(count_byte == -1)
		{
			free(str);
			return(NULL);
		}
		//meu left_str junta as duas strings e retorna a nova string;
		left_str = ft_strjoin(left_str, str);
	}
	free(str);
	return(left_str);	
}

char *get_next_line(int fd)
{
	static char	*str;
	char		*result_func;

	//Verifico se o meu arquivo ou o meu BUFFER_SIZE é nulo;
	if(!fd || !BUFFER_SIZE)
		return(NULL);
	result_func = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!result_func)
		return (NULL);
	str = read_line(fd, result_func);
	return(result_func);
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
