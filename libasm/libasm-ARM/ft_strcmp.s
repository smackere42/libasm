.section __TEXT, __text
.global _ft_strcmp           ; Экспортируем символ для macOS

_ft_strcmp:
    cbz x0, .check_null_s2   ; Если s1 == NULL, проверяем s2
    cbz x1, .return_neg1     ; Если s2 == NULL, возвращаем -1

.compare_loop:
    ldrb w2, [x0], #1        ; Загружаем байт из первой строки и сдвигаем указатель
    ldrb w3, [x1], #1        ; Загружаем байт из второй строки и сдвигаем указатель
    cmp w2, w3               ; Сравниваем байты
    bne .return_result       ; Если байты не равны, выходим
    cbz w2, .return_zero     ; Если достигли конца строки ('\0'), строки равны

    b .compare_loop          ; Повторяем цикл

.return_result:
    sub w0, w2, w3           ; Возвращаем разницу символов
    ret

.return_zero:
    mov w0, #0               ; Строки равны, возвращаем 0
    ret

.check_null_s2:
    cbz x1, .return_zero     ; Если s1 и s2 оба NULL, возвращаем 0
    b .return_neg1           ; Если только s1 NULL, возвращаем -1

.return_neg1:
    mov w0, #-1              ; Возвращаем -1, если один из аргументов NULL
    ret