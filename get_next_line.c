/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:47:44 by dbelarmi          #+#    #+#             */
/*   Updated: 2022/10/20 20:41:45 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// //função para ler linha por linha do meu file descriptor 
// char *read_line(int fd, char *left_str)
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

// char	*ft_line(char *left_str)//função de impressão da linha que sera retornada 
// {
// 	int			i;
// 	char		*str;

// 	i = 0;
// 	if (!left_str)
// 		return (NULL);
// 	while (left_str[i] && left_str[i] != '\n')//procuramos a primeira ocorrencia da quebra de linha ou o fim do texto, isso servirá para a alocação da string
// 		i++;
// 	str = (char *) malloc (sizeof(char) * (i + 2));//alocaremos memória com esse valor + 2, isso porque teremos que garantir espaço para os caracterer \0 e \n
// 	if (!str)
// 		return (NULL);
// 	i = 0;//zeramos o contador novamente, somente para não usar 2
// 	while (left_str[i] && left_str[i] != '\n')//agora copiaremos a linha ate que acabe o texto ou ache uma quebra de linha
// 	{
// 		str[i] = left_str[i];
// 		i++;
// 	}
// 	if (left_str[i] == '\n')//caso tenha saido do loop pela quebra de linha, temos que coloca-la na sting
// 	{
// 		str[i] = left_str[i];
// 		i++;
// 	}
// 	str[i] = '\0';//colocamos o byte nulo logo após a quebra de linha
// 	return (str);
// }

// char	*ft_newleft(char *left_str)//função para armazenar a posição inicial da proxima linha
// {
// 	int			s;
// 	int			i;
// 	char		*str;

// 	i = 0;
// 	s = 0;
// 	while (left_str[i] && left_str[i] != '\n')//iremos ate a primeira quebra de linha, de la que iremos começar a cópia
// 		i++;
// 	if (left_str[i] == '\0')//caso nao tenha uma proxima linha, liberamos aquela memoria e retornamos nulo
// 	{
// 		free(left_str);
// 		return (NULL);
// 	}
// 	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));//alocamos memória de tamanho que comece a contar depois da quebra de linha
// 	if (!str)
// 		return (NULL);
// 	i++;// passamos do byte de quebra de linha e copiaremos todo o restante
// 	while (left_str[i])
// 		str[s++] = left_str[i++];
// 	str[s] = '\0';
// 	free(left_str);//tendo esse texto salvo, podemos liberar a memória alocada anteriormente
// 	return (str);
// }
// char	*get_next_line(int fd)//aqui a função principal
// {
// 	char		*line;
// 	static char	*left_str;

// 	line = NULL;
// 	if (fd < 0 || BUFFER_SIZE <= 0)//caso algum parametro seja invalido, nosso programa ira terminar 
// 		return (NULL);
// 	left_str = read_line(fd, left_str);//verificamos se há alguma coisa para ser lida e se o file descriptor é valido
// 	if (!left_str)
// 		return (NULL);
// 	line = ft_line(left_str);//atribuimos a primeira linha que foi lida nessa variável, ela será nosso retorno
// 	left_str = ft_newleft(left_str);//aqui salvamos a posição que paramos de ler, para que no loop do main, continue o programa daqui
// 	if (line[0] == '\0')//garantimos que nao aja vazamento de memoria caso a linha atual não contenha nada escrito
// 	{
// 		free(left_str);//liberamos tudo oq foi alocado e podemos parar por aqui
// 		free(line);
// 		return (NULL);
// 	}
// 	return (line);//caso tudo tenha dado certo, a linha atual sera retornada
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