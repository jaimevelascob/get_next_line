#include <stdio.h>
#include <fcntl.h>

char    *get_next_line(int fd);
char    *prueba(int fd, char *res);

int main()
{
    int fd;
    char *res;

    fd = open("file.txt", O_RDONLY);
    //get_next_line(fd);
    //printf("%s\n", get_next_line(fd));
    //printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
}
