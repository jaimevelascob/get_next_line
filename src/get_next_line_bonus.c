/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 15:03:19 by jvelasco          #+#    #+#             */
/*   Updated: 2022/05/03 18:27:17 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line_bonus.h"

char	*save(char *line)
{
	int		i;
	char	*res;

	res = NULL;
	if (line[0] == '\0')
	{
		free(line);
		return (0);
	}
	i = 0;
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n' || line[0] == '\n')
		res = ft_strjoin(res, &line[i + 1]);
	free(line);
	return (res);
}

char	*ft_copy(char *res)
{
	char	*str;
	int		i;

	i = 0;
	while (res[i] != '\n' && res[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i = 0;
	while (res[i] != '\n' && res[i])
	{
		str[i] = res[i];
		i++;
	}
	if (res[i] == '\n')
		str[i++] = '\n';
	while (str[i])
		str[i++] = '\0';
	return (str);
}

char	*ft_fillres(int fd, char *res)
{
	int		i;
	char	line[BUFFER_SIZE + 1];

	i = 1;
	ft_bzero(line, sizeof(line));
	while (!ft_strchr(line, '\n') && i)
	{
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
			return (NULL);
		line[i] = '\0';
		res = ft_strjoin(res, line);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*res[4096];
	char		*str;

	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res[fd] = ft_fillres(fd, res[fd]);
	if (!res[fd])
		return (NULL);
	str = ft_copy(res[fd]);
	res[fd] = save(res[fd]);
	if (str[0] == '\0')
	{
		free(res[fd]);
		free(str);
		return (NULL);
	}
	return (str);
}
