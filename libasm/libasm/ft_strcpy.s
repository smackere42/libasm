BITS 64

SECTION .text
GLOBAL ft_strcpy

; rdi = dest, rsi = src

ft_strcpy:
    xor rax, rax              ; char temp
    push rdi                ; rdi => stack
    jmp loop                ; jump to loop

loop:
    cmp BYTE [rsi], 0       ; rsi = src if (src != \0)
    je ft_strcpy_end                 ; if (src == \0) return dst
    mov rax, [rsi]          ; temp = src[0]
    mov [rdi], rax          ; dst[0] = temp
    inc rdi                 ; *dst++
    inc rsi                 ; *src++
    jmp loop                ; jump to loop

ft_strcpy_end:
    mov BYTE [rdi], 0       ; add \0
    pop rax                 ; rax <= stack
    ret                     ; return ()