#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern int errno;

size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, const void *buf, size_t count);
char *ft_strdup(const char *s);

void	strlen_test()
{

	printf("--------------ft_strlen---------------\n\n");

	char *str1 = "123456789";
	char *str2 = "asdfasdfasdfasdf";
	char *str3 = "";
	char *str4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
	// char *str5 = NULL;

	printf("strlen is \t [%ld] \nft_strlen is \t [%ld]\n\n", strlen(str1), ft_strlen(str1));
	printf("strlen is \t [%ld] \nft_strlen is \t [%ld]\n\n", strlen(str2), ft_strlen(str2));
	printf("strlen is \t [%ld] \nft_strlen is \t [%ld]\n\n", strlen(str3), ft_strlen(str3));
	printf("strlen is \t [%ld] \nft_strlen is \t [%ld]\n\n", strlen(str4), ft_strlen(str4));
	//printf("strlen is \t [%ld] \nft_strlen is \t [%ld]\n\n", strlen(str5), ft_strlen(str5)); // will seg

}

void		strcpy_test()
{
	printf("\n--------------ft_strcpy---------------\n\n");

	// char	dst_one[250];
	char	dst_two[250];

	char *str1 = "123456789";
	char *str2 = "asdfasdfasdfasdf";
	char *str3 = "";
	char *str4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
	char *str5 = "this is a very looooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooong string to test a function";
	// char *str6 = NULL;

	printf("strcpy is \t [%s] \nft_strcpy is \t [%s]\n\n", strcpy(dst_two, str1), ft_strcpy(dst_two, str1));
	printf("strcpy is \t [%s] \nft_strcpy is \t [%s]\n\n", strcpy(dst_two, str2), ft_strcpy(dst_two, str2));
	printf("strcpy is \t [%s] \nft_strcpy is \t [%s]\n\n", strcpy(dst_two, str3), ft_strcpy(dst_two, str3));
	printf("strcpy is \t [%s] \nft_strcpy is \t [%s]\n\n", strcpy(dst_two, str4), ft_strcpy(dst_two, str4));
	printf("strcpy is \t [%s] \nft_strcpy is \t [%s]\n\n", strcpy(dst_two, str5), ft_strcpy(dst_two, str5));
	// printf("strcpy is \t [%s] \nft_strcpy is \t [%s]\n\n", strcpy(dst_two, str6), ft_strcpy(dst_two, str6));
}

void	strcmp_test()
{
	printf("\n--------------ft_strcmp---------------\n\n");

	char *str1 = "6666123456789";
	char *str2 = "6666asdfasdfasdfasdf";
	char *str3 = "";
	char *str4 = "------------------9------------------sdfsfsdfsfasdfasdf---------------asdfasdf";
	// char *str5 = NULL;

	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str1, str2), ft_strcmp(str1, str2));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str2, str3), ft_strcmp(str2, str3));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str3, str4), ft_strcmp(str3, str4));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str4, str3), ft_strcmp(str4, str3));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str3, str2), ft_strcmp(str3, str2));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str2, str1), ft_strcmp(str2, str1));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str1, str1), ft_strcmp(str1, str1));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str2, str2), ft_strcmp(str2, str2));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str3, str3), ft_strcmp(str3, str3));
	printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str4, str4), ft_strcmp(str4, str4));
	// printf("strcmp is \t [%d] \t ft_strcmp is \t [%d]\n", strcmp(str5, str4), ft_strcmp(str5, str4));
}

void 	read_test(void)
{
	printf("\n--------------ft_read---------------\n\n");

	char *file1 = "test.txt";
	char *file2 = "";
	char *buf1 = malloc(sizeof(char) * 50);
	char *buf2 = malloc(sizeof(char) * 50);
	int fd1 = open(file1, O_RDONLY);
	int	fd2 = open(file2, O_RDONLY);

	errno = 0;
	printf("read() return value \t [%zd]\n", read(fd1, buf1, 40));
	printf("read() read buf \t [%s]\n", buf1);
	printf("read() errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
	errno = 0;
	printf("ft_read() return value \t [%zd]\n", ft_read(fd1, buf1, 40));
	printf("ft_read() read buf \t [%s]\n", buf1);
	printf("ft_read() errno \t [%d] \t [%s]\n", errno, strerror(errno));
	printf("\n");

	errno = 0;
	printf("read() return value \t [%zd]\n", read(fd2, buf2, 40));
	printf("read() read buf \t [%s]\n", buf2);
	printf("read() errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
	errno = 0;
	printf("ft_read() return value \t [%zd]\n", ft_read(fd2, buf2, 40));
	printf("ft_read() read buf \t [%s]\n", buf2);
	printf("ft_read() errno \t [%d] \t [%s]\n", errno, strerror(errno));
	close(fd2);
	printf("\n");

	errno = 0;
	printf("read() return value \t [%zd]\n", read(fd1, 0, 40));
	printf("read() errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
	errno = 0;
	printf("ft_read() return value \t [%zd]\n", ft_read(fd1, 0, 40));
	printf("ft_read() errno \t [%d] \t [%s]\n", errno, strerror(errno));
	close(fd1);
	printf("\n");

	// errno = 0;
	// printf("read() return value \t [%zd]\n", read(0, buf1, 40));
	// printf("read() errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
	// errno = 0;
	// printf("ft_read() return value \t [%zd]\n", ft_read(0, buf1, 40));
	// printf("ft_read() errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
	// printf("\n");

	free(buf1);
	free(buf2);
}

void	write_test()
{
	printf("\n--------------ft_write---------------\n\n");
	char *buf = "TEST SENTENCE TO TEST WRITE.\n";
	int fd = 1;
	int n = strlen(buf);
	errno = 0;
	printf("write() return value \t\t [%zd]\n", write(fd, buf, n));
	printf("ft_write() return value \t [%zd]\n", ft_write(fd, buf, n));
	printf("\n");
	errno = 0;
	printf("write() return value \t\t [%zd]\n", write(fd, 0, n));
	printf("write() errno \t\t\t [%d] \t [%s]\n", errno, strerror(errno));
	printf("\n");
	errno = 0;
	printf("ft_write() return value \t [%zd]\n", ft_write(fd, 0, n));
	printf("ft_write() errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
	printf("\n");
	errno = 0;
	printf("write() return value \t\t [%zd]\n", write(-1, 0, n));
	printf("write() errno \t\t\t [%d] \t [%s]\n", errno, strerror(errno));
	printf("\n");
	errno = 0;
	printf("ft_write() return value \t [%zd]\n", ft_write(-1, 0, n));
	printf("ft_write() errno \t\t [%d] \t [%s]\n", errno, strerror(errno));
	printf("\n");
}

void	ft_strdup_test(void)
{
	printf("\n--------------ft_strdup---------------\n\n");
	printf("strdup \t\t [%s]\n", strdup("test1"));
	printf("ft_strdup \t [%s]\n", ft_strdup("test1"));
	printf("\n\n");
	printf("strdup \t\t [%s]\n", strdup("this is a very looooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooong string to test a function"));
	printf("ft_strdup \t [%s]\n", ft_strdup("this is a very looooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooong string to test a function"));
	printf("\n\n");
	printf("strdup \t\t [%s]\n", strdup(""));
	printf("ft_strdup \t [%s]\n", ft_strdup(""));
}

int 	main(void)
{
	strlen_test();
	strcpy_test();
	strcmp_test();
	read_test();
	write_test();
	ft_strdup_test();
	return 0;
}