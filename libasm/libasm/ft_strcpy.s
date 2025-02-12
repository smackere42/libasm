BITS 64
SECTION .text

GLOBAL ft_strcpy

ft_strcpy:
    xor rax, rax              ; Обнуляем rax (используется как временная переменная)
    push rdi                  ; Сохраняем указатель dst (rdi) в стек, чтобы вернуть его в конце
    jmp loop                  ; Переходим к циклу копирования

loop:
    cmp BYTE [rsi], 0         ; Проверяем, достигли ли конца строки src (если src[i] == '\0')
    je ft_strcpy_end          ; Если src[i] == '\0', переходим к завершению

    mov rax, [rsi]            ; Загружаем 8 байт из src в rax (оптимизация копирования)
    mov [rdi], rax            ; Копируем эти 8 байт в dst
    inc rdi                   ; Увеличиваем указатель dst (двигаемся к следующему символу)
    inc rsi                   ; Увеличиваем указатель src (двигаемся к следующему символу)
    jmp loop                  ; Повторяем цикл, пока не достигнем конца строки

ft_strcpy_end:
    mov BYTE [rdi], 0         ; Добавляем завершающий нулевой символ '\0' в конец dst
    pop rax                   ; Восстанавливаем исходный указатель dst из стека (возвращаем его)
    ret                       ; Возвращаем dst (указатель на начало строки)