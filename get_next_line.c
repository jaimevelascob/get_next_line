#include "get_next_line.h"

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
	while(line[i] != '\n' && line[i])
		i++;
	if (line[i] == '\n' || line[0] == '\n')
		res = ft_strjoin(res, &line[i + 1]);
	free(line);
	return (res);
}

char    *ft_copy(char *res)
{
	char	*str;
	int		i;

	i = 0;
	while(res[i] != '\n' && res[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i = 0;
	while(res[i] != '\n' && res[i])
	{
		str[i] = res[i];
		i++;
	}
	if(res[i] == '\n')
		str[i++] = '\n';
	while(str[i])
		str[i++] = '\0';
	return(str);
}

char    *ft_fillres(int fd,char *res)
{
	int		i;
    char	line[BUFFER_SIZE + 1];
	
	i = 1;
	ft_bzero(line, sizeof(line));
	while(!ft_strchr(line,'\n') && i)
	{
		i = read(fd, line, BUFFER_SIZE);
		if (i == -1)
		{
			free(line);
			return (NULL);
		}
		line[i] = '\0';
		res = ft_strjoin(res, line);
	}
    return (res);
}

char    *get_next_line(int fd)
{
    static char *res;
    char        *str;
	
	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = ft_fillres(fd, res);
	if (!res)
		return (NULL);
	str = ft_copy(res);
	res = save(res);
	if(str[0] == '\0')
	{
		free(res);
		free(str);
		return (NULL);
	}
    return (str); 
}

