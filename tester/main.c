#include "../inc/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

//char    *get_next_line(int fd);

int main()
{
    int fd;
	char *aux;

    fd = open("file.txt", O_RDONLY);
    printf("print: %s\n", aux = get_next_line(fd));
	free(aux);
    printf("print: %s\n", aux = get_next_line(fd));
	free(aux);
    //printf("\nprint: %s\n", get_next_line(fd));
    printf("print: %s\n", aux = get_next_line(fd));
	free(aux);
    system("leaks a.out");
	
}
