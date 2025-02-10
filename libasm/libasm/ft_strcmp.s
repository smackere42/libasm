BITS 64

SECTION .text

    GLOBAL ft_read
    extern __errno_location

ft_read:
    mov rax, 0                     ; Загружаем в rax номер системного вызова read (0)
    syscall                         ; Вызываем read из syscall

    cmp rax, 0                      ; Проверяем, rax >= 0?
    jge ft_read_end                 ; Если rax >= 0 (чтение успешно), выходим из функции


    neg rax                         ; Инвертируем rax (делаем его положительным, получаем код ошибки)
    mov rbx, rax                    ; Сохраняем код ошибки в rbx

    call __errno_location wrt ..plt  ; Вызываем __errno_location, получаем адрес переменной errno в rax
    mov [rax], ebx                   ; Записываем код ошибки по адресу errno

    mov rax, -1                      ; Возвращаем -1, чтобы сигнализировать об ошибке

ft_read_end:
    ret                              ; Завершаем функцию, результат остается в raxы