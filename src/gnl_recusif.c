/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_recusif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 14:54:11 by viporten          #+#    #+#             */
/*   Updated: 2021/10/25 16:01:06 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

static int	line_init(char **line, int offset, int res)
{
	(*line = malloc((offset + 1) * sizeof(char)));
	if ((*line) == NULL)
		return (-1);
	((*line)[offset]) = '\0';
	return (res);
}

static int	recursive_gnl(char **line, int fd, int offset)
{
	char	buff;
	int		ret;

	ret = read(fd, &buff, 1);
	if (ret == 1)
	{
		if (buff == '\n' || buff == '\0')
			return (line_init(line, offset, 1));
		else
		{
			ret = recursive_gnl(line, fd, offset + 1);
			if ((*line) != NULL)
				((*line)[offset]) = buff;
			return (ret);
		}
	}
	else if (ret == 0)
		return (line_init(line, offset, 0));
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char	buff;

	if (fd < 0 || !line || read(fd, &buff, 0) < 0)
	{
		return (-1);
	}
	*line = NULL;
	return (recursive_gnl(line, fd, 0));
}
