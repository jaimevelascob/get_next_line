#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(char *str, size_t i);
#endif
