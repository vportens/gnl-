/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 16:40:00 by victor            #+#    #+#             */
/*   Updated: 2019/11/27 12:01:21 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnew(int size)
{
	char	*new;

	new = malloc(sizeof(char *) * 1);
	new[0] = '\0';
	return (new);
}

static void	complet(char *s2, char *new, int i)
 {
 	int	j;
 
 	j = 0;
 	while (s2[j])
 	{
 		new[i + j] = s2[j];
 		j++;
 	}
 	new[i + j] = 0;
 	return ;
 }
 
 char		*ft_strjoin(char *s1, char *s2)
 {
 	int		i;
 	int		j;
 	char	*new;
 
 	i = 0;
 	j = 0;
 	if (s1 == 0 || s2 == 0)
 		return (0);
 	while (s1[i])
 		i++;
 	while (s2[j])
 		j++;
 	if (!(new = malloc(sizeof(char) * (i + j + 1))))
 		return (0);
 	i = 0;
 	while (s1[i])
 	{
 		new[i] = s1[i];
 		i++;
 	}
 	complet(s2, new, i);
 	return (new);
 }

char	*ft_strchr(char *s, int c)
{
	char	found;
	int		i;

	i = 0;
	found = c;
	while (s[i] && s[i] != found)
		i++;
	if (s[i] == '\0' && found != '\0')
		return (0);
	return (s + i);
}

char	*ft_substr(char *s, int start, int len)
{
	char				*new;
	int		i;

	i = 0;
	if (s == 0)
		return (0);
	if (start < len)
	{
		if (!(new = malloc(sizeof(char) * (len + 1))))
			return (0);
		while (s[start + i] && i < len)
		{
			new[i] = s[start + i];
			i++;
		}
		new[i] = 0;
	}
	else
	{
		if (!(new = malloc(sizeof(char))))
			return (0);
		new[0] = '\0';
	}
	return (new);
}
char	*ft_strdup(char *s1)
{
	int		i;
	char	*new;

	i = 0;
	while (s1[i])
		i++;
	if (!(new = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = 0;
	return (new);
}
