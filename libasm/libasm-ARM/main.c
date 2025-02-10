#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/*
** Useful macros
*/
#define STRLEN(x)			printf("`%s` = %d (%d)\n", SAFE_STR(x), ft_strlen(x), (int)strlen(x))
#define STRCMP(a, b)		printf("`%s`:`%s` = %d (%d)\n", SAFE_STR(a), SAFE_STR(b), ft_strcmp(a, b), strcmp(SAFE_STR(a), SAFE_STR(b)))
#define WRITE(s, x)		printf("^%ld (`%s`:%ld)\n", ft_write(STDOUT_FILENO, s, x), SAFE_STR(s), x)
#define READ(b, x)			r = ft_read(STDIN_FILENO, buffer, x); printf("`%s`:%ld\n", buffer, r)
#define DUP(s)				tmp = ft_strdup(s); printf("`%s` (`%s`)\n", SAFE_STR(tmp), SAFE_STR(s)); free(tmp); tmp = NULL
#define SAFE_STR(s)         ((s) ? (s) : "(null)")

/*
** Function prototypes
*/
int		ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
ssize_t	ft_write(int fd, const void *buf, size_t nbyte);
ssize_t	ft_read(int fd, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

/*
** Start of main program
*/
int main(void)
{
	int		i;
	long	r;
	char	buffer[100];
	char	*tmp;
	char	*tmp2;

	// Initialize buffer
	r = 0;
	i = 0;
	while (i < 100)
		buffer[i++] = 0;

	/*
	** Test ft_strlen
	*/
	printf("-- ft_strlen\n");
	STRLEN("");
	STRLEN("toto");
	STRLEN("totototo");
	STRLEN("0123456789abcdef");
	STRLEN("42");
	STRLEN("1");
	printf("- done\n");

	/*
	** Test ft_strcmp
	*/
	printf("\n-- ft_strcmp\n");
	STRCMP("", "");
	STRCMP("toto", "toto");
	STRCMP("", "toto");
	STRCMP("toto", "");
	STRCMP("toto", "totobar");
	STRCMP("TOTO", NULL);
	STRCMP(NULL, "TOTO");
	STRCMP(NULL, NULL);
	printf("- done\n");

	/*
	** Test ft_strcpy
	*/
	printf("\n-- ft_strcpy\n");
	printf("`%s` (`toto`)\n", ft_strcpy(buffer, "toto"));
	printf("`%s` (empty)\n", ft_strcpy(buffer, ""));
	if (ft_strcpy(buffer, "long message"))
		printf("`%s` (`long message`)\n", buffer);
	if (ft_strcpy(buffer, NULL))
		printf("`%s` (NULL > not modified)\n", buffer);
	printf("- done\n");

	/*
	** Test ft_write
	*/
	printf("\n-- ft_write\n");
	WRITE("toto", 4L);
	WRITE("totototo", 4L);
	WRITE("totototo", 8L);
	WRITE("toto", 2L);
	printf("- done\n");

	/*
	** Test ft_read
	*/
	printf("\n-- ft_read (Makefile)\n");
	READ(buffer, 50);
	READ(buffer, 25);
	READ(buffer, 4);
	READ(buffer, 26);
	READ(buffer, 14);
	READ(buffer, 0);
	printf("- done\n");

	/*
	** Test ft_strdup
	*/
	printf("\n-- ft_strdup\n");
	tmp2 = ft_strdup("toto");
	DUP(tmp2);
	free(tmp2);
	DUP("totobar");
	DUP("long message");
	DUP("");
	DUP((char *)NULL);
	printf("- done\n");

	return (0);
}