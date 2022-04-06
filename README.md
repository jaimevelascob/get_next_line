# get_next_line
In this work we have to read the text file pointed to by the file descriptor, one line at a time, using static variables, without lseek() and compiling with "-D BUFFER_SIZE=n" to define the buffer size for read.
Get_next_line.c:
	The main function is get_next_line(int fd). Here we control and call the functions. The programm could divide in 3 steps.
	1. Fill the static variable with the funciton ft_fillres(int fd, char *res);

	2. Copy the res in a new dinamic char, saving the line and the '\n' that we use to separate. This is the one that we are going to return.
	
	3. Before return, we cut the res with save(res). To free the line that we return.

Get_next_line_utils.c:
	Here we have the functions we use.
	- Char    *ft_strchr(char *s, char c) to search the '\n' character in the read.
	- void	ft_bzero(char *str, size_t i) to inicializated.
	-int ft_strlen(char *str) to count the len and know what we have to copy.
	-char *ft_strjoin(char *s1, char *s2) to concatenated and fill the static variable.
	I-void *ft_memcpy(void *dst, const void *src, size_t n) for copy.
Get_next_line.h:
	Fo the prototypes of functions.
