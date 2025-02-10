#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_strdup(const char *s);

int main() {
    const char *original = "Hel12312lo, ARqweqweqweqweq111112312312312weqeqwe121 312 adasdasMqw4!";
    char *dup_asm;
    char *dup_orig;

printf("Original string: '%s'\n", original);

dup_asm = ft_strdup(original);
if (dup_asm == NULL) {
    printf("Error: '%s'\n", original);
    perror("ft_strdup failed");
    return 1;
}
printf("ASM strdup result: '%s'\n", dup_asm);

dup_orig = strdup(original);
if (dup_orig == NULL) {
    perror("strdup failed");
    free(dup_asm);
    return 1;
}
printf("Original strdup result: '%s'\n", dup_orig);

if (strcmp(dup_asm, dup_orig) == 0) {
    printf("\033[0;32mPASS: ft_strdup matches strdup\033[0m\n");
} else {
    printf("\033[0;31mFAIL: ft_strdup does not match strdup\033[0m\n");
}

free(dup_asm);
free(dup_orig);

    return 0;
}