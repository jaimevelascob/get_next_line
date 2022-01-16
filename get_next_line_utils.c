#include "get_next_line.h"

char    *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t  i;
	size_t  j;
	char    *str;

	str = (char*)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char    *ft_strchr(char *s, int c)
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

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

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
    }
    return new;
}

void    *ft_memcpy(void *dst, const void *src, size_t n)
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
