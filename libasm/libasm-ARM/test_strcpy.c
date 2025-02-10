#include <stdio.h>
#include <string.h> // Для оригинальной strcpy

// ANSI коды для цветов
#define COLOR_GREEN "\033[0;32m"
#define COLOR_RED "\033[0;31m"
#define COLOR_RESET "\033[0m" // Сброс цвета

char *ft_strcpy(char *dest, const char *src);

int main() {
    char src[] = "Hello, ARM!";
    char dest_asm[20];
    char dest_orig[20];

    // Вызов вашей реализации
    ft_strcpy(dest_asm, src);

    // Вызов оригинальной реализации
    strcpy(dest_orig, src);

    // Вывод результатов
    printf("Source: %s\n", src);
    printf("ASM Destination: %s\n", dest_asm);
    printf("Original Destination: %s\n", dest_orig);

    // Проверка соответствия
    if (strcmp(dest_asm, dest_orig) == 0) {
        printf(COLOR_GREEN "PASS: ft_strcpy matches strcpy.\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_strcpy does not match strcpy.\n" COLOR_RESET);
    }

    return 0;
}