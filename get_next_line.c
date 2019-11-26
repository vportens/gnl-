/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:04:18 by victor            #+#    #+#             */
/*   Updated: 2019/11/22 19:00:33 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h> //
#include <limits.h>
#include <stdlib.h>
//#define BUFFER_SIZE = 32 //


int	complet_gnl(int fd, char **line, char **str)
{
	char	*tmp;
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		*line = ft_substr(str[fd], 0, len);
		tmp = ft_strdup(str[fd] + len);
		free(str[fd]);
		str[fd] = tmp;
		if (str[fd][0] == '\0')
			free(str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		*line = ft_substr(str[fd], 0, len);
		free(str[fd]);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			value;
	static char	*str[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	if (line == NULL || fd < 0)
		return (-1);
	while ((value = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[BUFFER_SIZE] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			value = 0;
	}
	if (value < 0)
		return (-1);
	if ((value == 0 && str[fd] == NULL) || (value == 0 && str[fd][0] == '\0'))
		return (0);
	return (complet_gnl(fd, line, str));	
}
