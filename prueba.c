#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strchr(char *s, int c);
char    *ft_strjoin(char *s1, char *s2);
int     ft_strlen(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_copy(char *res);

int buffersize = 4;

char    *ft_copy(char *res)
{
    char *str;
    int flag;
    static int i = 0;

    flag = i;
    while(res[i] != '\n' && res[i])
        i++;
    if(res[i] == '\n')
    {
        str = ft_substr(res, flag, (i-flag));
        i++;
    }
    else
       str = ft_substr(res, flag, i);
    return str;
}

char    *prueba(int fd,char *res)
{
    int i;
    char *line;
    
    line = malloc(sizeof(char) * (buffersize + 1));
    if (!line)
    {
        free(line);
        return (NULL);
    }
    while (!ft_strchr(line, '\n'))
    {
        i = read(fd, line, buffersize);
        printf("%d\n", i);
        if (i == 0)
            return (NULL);
        res = ft_strjoin(res, line);
    }
    free(line);
    return (res);
}
char    *get_next_line(int fd)
{
    static char *res;
    char *str;

    if (fd < 0 || buffersize <= 0)
        return (NULL);
    // llenar res
    res = prueba(fd, res);
    if (res == NULL)
        str == NULL;
    // llenar str
    else 
        str = ft_copy(res);
    return str; 
}
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*news;
	size_t			i;
	size_t			size;

	if (!s)
		return (0);
	size = ft_strlen((char *)s);
	if (size > len)
		size = len;
	news = malloc(size + 1);
	if (!news)
		return (0);
	if (start >= (unsigned int)ft_strlen((char *)s) || start > len)
	{
		free(news);
		return (NULL);
	}
	i = 0;
	while (s[i + start] && i < len)
	{
		news[i] = s[start + i];
		i++;
	}
	news[i] = 0;
	return (news);
}

// encontrar 
char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (0);
}

// tamaño
int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}
//unir
char    *ft_strjoin(char *s1, char *s2)
{
    int s1_size;
    int s2_size;
    char    *new;
    
    if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
    s1_size = ft_strlen(s1);
    s2_size = ft_strlen(s2);
    if (s1_size != 0 || s2_size != 0)
    {
        new = malloc(sizeof(char) * (s1_size + s2_size +1));
        if (!new)
            return (NULL);

        ft_memcpy(new, s1,s1_size);
        ft_memcpy(&new[s1_size], s2, s2_size);
        new[s1_size + s2_size] = '\0';
    }
    return new;
}


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dest1;
	const char	*src1;

	if (!src && !dst)
		return (NULL);
	dest1 = dst;
	src1 = src;
	i = 0;
	while (i < n && (dest1[i] || src1[i]))
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest1);
}
