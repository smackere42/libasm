BITS 64

SECTION .text

    GLOBAL ft_read
    extern __errno_location

ft_read:
    mov rax, 0                     ; Загружаем в rax номер системного вызова read (0)
    syscall                         ; Вызываем syscall (системный вызов read)
                                    ; После вызова:
                                    ; - rax содержит количество прочитанных байтов или ошибку (если < 0)

    cmp rax, 0                      ; Проверяем, больше ли rax (результат syscall) нуля
    jge ft_read_end                 ; Если rax >= 0, то ошибок нет, выходим из функции

    neg rax                         ; Инвертируем rax (делаем его положительным, чтобы получить код ошибки)
    mov rbx, rax                    ; Сохраняем код ошибки в rbx

    call __errno_location wrt ..plt  ; Вызываем __errno_location, он возвращает указатель на errno в rax
    mov [rax], ebx                   ; Сохраняем код ошибки в errno

    mov rax, -1                      ; Возвращаем -1 в случае ошибки

ft_read_end:
    ret                              ; Завершаем функцию, результат остается в rax