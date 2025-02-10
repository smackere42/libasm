BITS 64

    SECTION .text

        GLOBAL ft_strlen

ft_strlen:
    xor rax, rax            ; Обнуляем rax (используется для подсчета длины)
    mov rdi, rdi            ; Загружаем указатель на строку в rdi (он уже там, но явно указываем)
    
.loop:
    cmp BYTE [rdi], 0       ; Проверяем, равен ли текущий символ '\0' (окончание строки)
    je ft_strlen_end                ; Если да, переходим к завершению

    inc rdi                 ; Двигаем указатель на следующий символ (rdi++)
    inc rax                 ; Увеличиваем счетчик длины (rax++)
    jmp .loop               ; Повторяем цикл

ft_strlen_end:
    ret                     ; Возвращаем длину строки (rax)