.section __TEXT, __text
.global _ft_write
.extern _errno

_ft_write:
    stp x29, x30, [sp, #-16]!           ; Сохраняем frame pointer и return address
    mov x29, sp                         ; Обновляем frame pointer

    cmp x0, #0                          ; Проверяем `fd < 0`
    b.lt handle_invalid_fd              ; Если `fd` < 0, обработка ошибки

    cmp x2, #0                          ; Проверяем `count < 0`
    b.lt handle_invalid_count           ; Если `count` < 0, обработка ошибки

    movz x16, #0x2000                   ; macOS syscall prefix
    movk x16, #0x0004, lsl #0           ; Код `write` (0x200004)
    svc #0                              ; Вызов системного вызова

    cmp x0, #0                          ; Проверяем, была ли ошибка (если x0 < 0)
    b.ge write_done                     ; Если `x0 >= 0`, всё хорошо, выходим

    neg x0, x0                          ; Преобразуем ошибку в положительное число

    adrp x1, _errno@GOTPAGE             ; Загружаем адрес `_errno`
    ldr  x1, [x1, _errno@GOTPAGEOFF]    ; Получаем точный адрес
    str  w0, [x1]                       ; Устанавливаем errno
    mov  x0, #-1                        ; Возвращаем -1

write_done:
    ldp x29, x30, [sp], #16             ; Восстанавливаем frame pointer и return address
    ret

handle_invalid_fd:
    adrp x1, _errno@GOTPAGE
    ldr  x1, [x1, _errno@GOTPAGEOFF]
    mov  w0, #9                    ;EBADF (если fd < 0)
    str  w0, [x1]
    mov  x0, #-1                    ; Возвращаем -1
    b write_done

handle_invalid_count:
    adrp x1, _errno@GOTPAGE
    ldr  x1, [x1, _errno@GOTPAGEOFF]
    mov  w0, #22                   ; ✅ EINVAL (если count < 0)
    str  w0, [x1]
    mov  x0, #-1                    ; Возвращаем -1
    b write_done