/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:06:05 by dbelarmi          #+#    #+#             */
/*   Updated: 2022/10/20 14:43:25 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	size;

	size = 0;
	while (s && s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*str_dest;
	int		sd;
	int		i;

	sd = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	str_dest = (char *)malloc(sizeof(char) * (sd));
	if (str_dest == 0)
		return (NULL);
	i = 0;
	sd = 0;
	while (s1 && s1[i] != '\0')
	{
		str_dest[sd] = s1[i];
		sd++;
		i++;
	}
	i = 0;
	while (s2 && s2[i] != '\0')
	{
		str_dest[sd] = s2[i];
		sd++;
		i++;
	}
	str_dest[sd] = '\0';
	return (str_dest);
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