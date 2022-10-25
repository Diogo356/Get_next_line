/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:06:05 by dbelarmi          #+#    #+#             */
/*   Updated: 2022/10/25 14:15:27 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	s;

	s = 0;
	if (!str)
		return (0);
	while (str[s])
		s++;
	return (s);
}

char	*ft_strchr(char *s, int c)
{
	int	find;

	find = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[find])
	{
		if (s[find] == (char) c)
			return ((char *)&s[find]);
		find ++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buffer)
{
	char			*new_str;
	size_t			s;
	size_t			n;
	int				lenstr;

	lenstr = ft_strlen(left_str);
	s = 0;
	n = 0;
	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	new_str = malloc (sizeof(char) * (lenstr + ft_strlen(buffer)) + 1);
	if (new_str == NULL)
		return (NULL);
	while (left_str[n] != '\0')
		new_str[n++] = left_str[s++];
	s = 0;
	while (buffer[s])
		new_str[n++] = buffer[s++];
	new_str[n] = '\0';
	free(left_str);
	return (new_str);
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*p;

	if (nelem == 0 || elsize == 0 || nelem > 2147483647 || elsize > 2147483647)
		return (NULL);
	p = malloc (nelem * elsize);
	if (p == 0)
		return (p);
	ft_bzero (p, nelem * elsize);
	return (p);
}
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	if (n >= 0)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)s)[i] = '\0';
			i++;
		}		
	}
}