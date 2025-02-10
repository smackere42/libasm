.section __TEXT, __text
.global _ft_strcpy

_ft_strcpy:
    stp x29, x30, [sp, #-16]!  ; Сохраняем frame pointer и return address
    mov x29, sp                ; Обновляем frame pointer

    cbz x0, return_null         ; Если `dest == NULL`, вернуть NULL
    cbz x1, return_null         ; Если `src == NULL`, вернуть NULL

    mov x2, #0                  ; x2 = индекс

copy_loop:
    ldrb w3, [x1, x2]           ; Читаем байт из src
    strb w3, [x0, x2]           ; Пишем в dest
    cmp w3, #0                  ; Если `\0`, конец строки
    add x2, x2, #1              ; Увеличиваем индекс
    b.ne copy_loop              ; Продолжаем копирование

    mov x0, x0                  ; Возвращаем `dest`
    ldp x29, x30, [sp], #16     ; Восстанавливаем frame pointer и return address
    ret

return_null:
    mov x0, #0
    ret