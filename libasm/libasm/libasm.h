#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define BUFFER_SIZE 512

ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
size_t		ft_strlen(const char *s);
ssize_t		ft_write(int fildes, const void *buf, size_t nbyte);
char		*ft_strdup(const char *s1);