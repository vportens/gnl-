/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:23:55 by victor            #+#    #+#             */
/*   Updated: 2019/11/26 17:10:32 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <limits.h>
#include <stdlib.h>


int	get_next_line(int fd, char **line);
char	*ft_strnew(int size);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, int start, int len);
char	*ft_strchr(char *s, int c);
char		*ft_strjoin(char *s1, char *s2);

#endif
