#include <unistd.h>
#include <stdio.h>
#include <string.h>

// Объявление вашей функции
ssize_t ft_write(int fd, const void *buf, size_t count);

int main() {
    char buffer[256];  // Буфер для ввода сообщения
    ssize_t bytes_read;

    // Чтение сообщения из stdin
    write(1, "Enter your message: ", 20);
    bytes_read = read(0, buffer, sizeof(buffer) - 1);

    if (bytes_read < 0) {
        write(2, "Error reading input\n", 20); // Сообщение об ошибке
        return 1;
    }

    buffer[bytes_read] = '\0'; // Завершаем строку

    // Используем ft_write для вывода
    write(1, "Output using ft_write:\n", 23);
    ssize_t ft_result = ft_write(1, buffer, bytes_read);

    if (ft_result < 0) {
        write(2, "Error occurred while using ft_write\n", 36);
        return 1;
    }

    // Используем оригинальный write для проверки
    write(1, "Output using original write:\n", 29);
    ssize_t orig_result = write(1, buffer, bytes_read);

    if (orig_result < 0) {
        write(2, "Error occurred while using original write\n", 42);
        return 1;
    }

    // Сравнение результатов
    if (ft_result == orig_result) {
        write(1, "PASS: ft_write matches original write\n", 38);
    } else {
        write(2, "FAIL: ft_write does not match original write\n", 46);
    }

    return 0;
}