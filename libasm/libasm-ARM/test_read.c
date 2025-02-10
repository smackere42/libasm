#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

// Объявление вашей функции
ssize_t ft_read(int fd, void *buf, size_t count);

int main() {
    char buffer[256];
    ssize_t ft_result, orig_result;

    // Чтение с помощью ft_read
    write(1, "Enter text (ft_read): ", 22);
    ft_result = ft_read(0, buffer, sizeof(buffer) - 1);

    if (ft_result < 0) {
        perror("ft_read error");
    } else {
        buffer[ft_result] = '\0'; // Завершаем строку
        write(1, "ft_read output: ", 16);
        write(1, buffer, ft_result);
    }

    // Чтение с помощью оригинальной read
    write(1, "\nEnter text (read): ", 21);
    orig_result = read(0, buffer, sizeof(buffer) - 1);

    if (orig_result < 0) {
        perror("read error");
    } else {
        buffer[orig_result] = '\0'; // Завершаем строку
        write(1, "read output: ", 13);
        write(1, buffer, orig_result);
    }

    // Сравнение результатов
    if (ft_result == orig_result) {
        write(1, "\n\033[0;32mPASS: ft_read matches read\033[0m\n", 38);
    } else {
        write(1, "\n\033[0;31mFAIL: ft_read does not match read\033[0m\n", 45);
    }

    return 0;
}