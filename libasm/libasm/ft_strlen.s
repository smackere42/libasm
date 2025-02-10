BITS 64

SECTION .text
GLOBAL ft_strlen


ft_strlen:
    xor rax, rax;                ; int i = 0
    cmp rdi, 0;                   ; char *str == NULL
    je ft_strlen_end               ; if (char *str == NULL) => return (NULL)
    jmp loop;                    ; jump to loop

loop:
    cmp BYTE [rdi + rax], 0;     ; if (*str == '\0')
    je ft_strlen_end              ; if (!str) return (i)
    inc rax;                     ; i++
    jmp loop;                    ; jump to loop

ft_strlen_end:
    ret;                         ; return (i) d