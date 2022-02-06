#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

char    *get_next_line(int fd);
char    *prueba(int fd, char *res);
int		ft_strlen(char *str);

int main()
{
    int fd;
	char *aux;

    fd = open("file.txt", O_RDONLY);
    //get_next_line(fd);
    //printf("%s\n", get_next_line(fd));
		//printf("%s\n", get_next_line(fd));
    printf("print: %s\n", aux = get_next_line(fd));
	free(aux);
    printf("print: %s\n", aux = get_next_line(fd));
	free(aux);
    //printf("\nprint: %s\n", get_next_line(fd));
    printf("print: %s\n", get_next_line(fd));
	//system("leaks a.out");
	
}
