/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbelarmi <dbelarmi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:48:08 by dbelarmi          #+#    #+#             */
/*   Updated: 2022/10/25 14:14:48 by dbelarmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *str);
char	*get_next_line(int fd);
char	*find_break_line(char *left_str);
char	*read_line(int fd, char *left_str);
char	*new_position(char *left_str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nelem, size_t elsize);

#endif
