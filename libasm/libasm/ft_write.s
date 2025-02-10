BITS 64

SECTION .text

    GLOBAL ft_write
        extern __errno_location

; ssize_t write(int fd, const void *buf, size_t count)
; Входные параметры (передаются через регистры):
; - rdi: файловый дескриптор (fd)
; - rsi: указатель на буфер (buf)
; - rdx: количество байтов для записи (count)
ft_write:
    mov rax, 1                 ; Загружаем номер системного вызова write (1) в rax
    syscall                    ; Вызываем системный вызов write(rdi, rsi, rdx)

    cmp rax, 0                 ; Проверяем, rax >= 0 (успешная запись?)
    jge ft_write_end           ; Если да, выходим из функции

    neg rax                    ; Инвертируем rax, делая его положительным (получаем код ошибки)
    mov rbx, rax               ; Сохраняем код ошибки в rbx

    call __errno_location wrt ..plt  ; Вызываем __errno_location, чтобы получить указатель на errno
    mov [rax], ebx             ; Записываем код ошибки в errno

    mov rax, -1                ; Возвращаем -1 (индикатор ошибки)

ft_write_end:
    ret                        ; Возвращаем rax (количество записанных байтов или -1 при ошибке)