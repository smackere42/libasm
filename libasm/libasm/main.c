#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

// Объявляем внешние функции из libasm
size_t ft_strlen(const char *s);
char *ft_strcpy(char *dest, const char *src);
int ft_strcmp(const char *s1, const char *s2);
ssize_t ft_read(int fd, void *buf, size_t count);
ssize_t ft_write(int fd, const void *buf, size_t count);
char *ft_strdup(const char *s);

// Тест для ft_strlen
void test_strlen()
{
    printf("\n--- TESTING ft_strlen ---\n");
    char *tests[] = {"Hello", "", "1234567890", "A very long string to test the function", NULL};

    for (int i = 0; tests[i]; i++)
    {
        printf("strlen: [%lu], ft_strlen: [%lu]\n", strlen(tests[i]), ft_strlen(tests[i]));
    }
}

// Тест для ft_strcpy
void test_strcpy()
{
    printf("\n--- TESTING ft_strcpy ---\n");
    char src[] = "Hello, world!";
    char dest1[50], dest2[50];

    strcpy(dest1, src);
    ft_strcpy(dest2, src);

    printf("strcpy: [%s]\n", dest1);
    printf("ft_strcpy: [%s]\n", dest2);
}

// Тест для ft_strcmp
void test_strcmp()
{
    printf("\n--- TESTING ft_strcmp ---\n");
    char *s1 = "Hello";
    char *s2 = "Hello";
    char *s3 = "Hellp";
    char *s4 = "Helln";

    printf("strcmp: [%d], ft_strcmp: [%d]\n", strcmp(s1, s2), ft_strcmp(s1, s2));
    printf("strcmp: [%d], ft_strcmp: [%d]\n", strcmp(s1, s3), ft_strcmp(s1, s3));
    printf("strcmp: [%d], ft_strcmp: [%d]\n", strcmp(s1, s4), ft_strcmp(s1, s4));
}

// Тест для ft_read
void test_read()
{
    printf("\n--- TESTING ft_read ---\n");
    char buffer[100];
    int fd = open("test.txt", O_RDONLY);

    if (fd < 0)
    {
        perror("Error opening file");
        return;
    }

    ssize_t ret1 = read(fd, buffer, 50);
    buffer[ret1] = '\0';
    printf("read: [%zd], buffer: [%s]\n", ret1, buffer);

    lseek(fd, 0, SEEK_SET); // Перемещаем указатель в начало файла
    ssize_t ret2 = ft_read(fd, buffer, 50);
    buffer[ret2] = '\0';
    printf("ft_read: [%zd], buffer: [%s]\n", ret2, buffer);

    close(fd);
}

// Тест для ft_write
void test_write()
{
    printf("\n--- TESTING ft_write ---\n");
    char *text = "Hello, ft_write!\n";

    ssize_t ret1 = write(1, text, strlen(text));
    printf("write returned: [%zd]\n", ret1);

    ssize_t ret2 = ft_write(1, text, strlen(text));
    printf("ft_write returned: [%zd]\n", ret2);
}

// Тест для ft_strdup
void test_strdup()
{
    printf("\n--- TESTING ft_strdup ---\n");
    char *str = "Hello, strdup!";
    char *dup1 = strdup(str);
    char *dup2 = ft_strdup(str);

    printf("strdup: [%s]\n", dup1);
    printf("ft_strdup: [%s]\n", dup2);

    free(dup1);
    free(dup2);
}

int main()
{
    test_strlen();
    test_strcpy();
    test_strcmp();
    test_read();
    test_write();
    test_strdup();
    return 0;
}