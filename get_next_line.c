/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:47:44 by dbelarmi          #+#    #+#             */
/*   Updated: 2022/10/19 20:18:56 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// //função para ler linha por linha do meu file descriptor 
// char	*read_line(int fd, char *left_str)
// {
// 	char *str;
// 	int count_byte;
	
// 	//alloca a memoria nescessaria com o \0 no final;
// 	str = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);

// 	//verifica se a alocação correu bem;
// 	if(!str)
// 	{
// 		free(str);
// 		return(NULL);
// 	}
	
// 	//meu contador começa em 1 por que não pode ser zero;
// 	count_byte = 1;

// 	//loop que verifica o \n na string e se o meu contador é diferente de zero;
// 	while (!ft_strchr(str, '\n') && count_byte != 0)
// 	{
// 		//meu contador recebe o valor de retorno read;
// 		count_byte = read(fd, str, BUFFER_SIZE);

// 		//verifica se o read correu bem;
// 		if(count_byte == -1)
// 		{
// 			free(str);
// 			return(NULL);
// 		}
// 		//meu left_str junta as duas strings e retorna a nova string;
// 		left_str = ft_strjoin(left_str, str);
// 	}
// 	//desoloco o str;
// 	free(str);
// 	//retorno o left;
// 	return(left_str);	
// }

// char *find_line_break(char *left_str)//função para achar a quebra de linha;
// {
// 	char str;
// 	int i;

// 	i = 0;
// 	while (left_str[i] || left_str[i] != '\n')
// 		i++;
// 	str = ft_calloc(sizeof(char), (i + 2))
// 	if(!str)
// 		return(NULL);
// 	i = 0;
// 	while (!left_str[i] || left_str != '\n')
// 	{
// 		str[i] = left_str[i];
// 		i++;
// 	}
// 	if (!left_str || left_str == '\n')
// 	{
// 		str[i] = left_str[i]
// 		i++;
// 	}
// 	return(str);
// }

char	*new_position(char *left_str)//função para armazenar a posição inicial da proxima linha;
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
	str = ft_calloc(sizeof(char), (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	printf("%d\n", i);
	while (left_str[i])
		str[s++] = left_str[i++];
	free(left_str);
	return (str);
}

// char *get_next_line(int fd)
// {
// 	static char	*str;
// 	char		*result_func;

// 	//Verifico se o meu arquivo ou o meu BUFFER_SIZE é nulo;
// 	if(!fd || !BUFFER_SIZE)
// 		return(NULL);
	
	
// }

// int main(void)
// {
// 	int fd;
// 	char *line;

// 	fd = open("texto.txt", O_RDONLY);
// 	line = "";
// 	while (line != NULL)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 	}
// 	fd = close(fd);
// 	return (0);
// }
