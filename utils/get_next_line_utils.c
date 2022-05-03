/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvelasco <jvelasco@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 19:33:35 by jvelasco          #+#    #+#             */
/*   Updated: 2022/05/03 18:27:52 by jvelasco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	if (s[i] == c)
		return ((char *)s + i);
	return (0);
}

void	ft_bzero(char *str, size_t i)
{
	while (i--)
		*(str++) = 0;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		len2;
	char	*str;

	if (!s1)
	{
		s1 = malloc(sizeof (char) * 1);
		s1[0] = '\0';
	}
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (len + len2 + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, len);
	ft_memcpy(&str[len], s2, len2);
	str[len + len2] = '\0';
	free(s1);
	return (str);
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
