#include <stdio.h>
#include <string.h>

size_t ft_strlen(const char *str);  // Без подчеркивания в C

int main() {
    const char *test = "Hello, ARM!12312312312312312312312312oiyo32iuycdnqwimd22HWQIHDGWHOlohiugdsda";
    printf("Mine length: %zu\n", ft_strlen(test));
    printf("Real length: %zu\n", strlen(test));
    return 0;
}