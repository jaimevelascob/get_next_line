#include "get_next_line.h"

char    *ft_copy(char *res)
{
    char        *str;
    int         flag;
    static int  i = 0;

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

char    *ft_fillres(int fd,char *res)
{
    int i;
    char *line;
    
    line = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!line)
    {
        free(line);
        return (NULL);
    }
    while (!ft_strchr(line, '\n'))
    {
        i = read(fd, line, BUFFER_SIZE);
        if (i == 0)
            return (NULL);
        res = ft_strjoin(res, line);
    }
    free(line);
    return (res);
}

int check_res(char *res)
{
    static int i = 0;
   
    while(res[i])
    {
        if (res[i] == '\n')
        {
            i++;
            return (0);
        } 
        i++;
    }
    return (1);
}

char    *get_next_line(int fd)
{
    static char *res;
    int         check;
    char        *str;

    check = 1;
    str = NULL;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return NULL;
    if (res)
        check = check_res(res);
    printf("c :%d\n", check);
    if (check == 1)
    {
        res = ft_fillres(fd, res);
        printf("res: %s\n",res);
        if (res != NULL)
            check = check_res(res);
        else
        {
            printf("a\n");
            return NULL;
        }    
    }
    str = ft_copy(res);
    return (str); 
}

