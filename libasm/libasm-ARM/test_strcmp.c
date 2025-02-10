#include <stdio.h>
#include <string.h>

#define COLOR_GREEN "\033[0;32m"
#define COLOR_RED "\033[0;31m"
#define COLOR_RESET "\033[0m"

int ft_strcmp(const char *s1, const char *s2);

int main() {
    const char *str1 = "Hello, World!";
    const char *str2 = "Hello, ARM!";
    int asm_result = ft_strcmp(str1, str2);
    int orig_result = strcmp(str1, str2);

    printf("Strings to compare:\n");
    printf("String 1: %s\n", str1);
    printf("String 2: %s\n", str2);
    printf("ASM Result: %d\n", asm_result);
    printf("Original Result: %d\n", orig_result);

    if ((asm_result < 0 && orig_result < 0) ||
        (asm_result == 0 && orig_result == 0) ||
        (asm_result > 0 && orig_result > 0)) {
        printf(COLOR_GREEN "PASS: ft_strcmp matches strcmp.\n" COLOR_RESET);
    } else {
        printf(COLOR_RED "FAIL: ft_strcmp does not match strcmp.\n" COLOR_RESET);
    }

    return 0;
}