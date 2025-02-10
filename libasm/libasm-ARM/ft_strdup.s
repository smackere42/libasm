.section __TEXT, __text
.global _ft_strdup
.extern _malloc
.extern _ft_strlen
.extern _ft_strcpy

_ft_strdup:
    stp x29, x30, [sp, #-16]!    // Сохранение регистров
    mov x29, sp

    cbz x0, return_null          // Проверяем NULL, если да — возвращаем NULL

    mov x1, x0                   // Сохраняем указатель на строку
    bl _ft_strlen                // Вызываем ft_strlen(s1), длина строки -> x0
    add x0, x0, #1               // Добавляем 1 для `\0`
    bl _malloc                   // Выделяем память (len + 1)

    cbz x0, return_null          // Если malloc вернул NULL, вернуть NULL

    mov x2, x0                   // x2 = dest (сохранить указатель для возврата)
    mov x1, x1                   // x1 = src (восстанавливаем исходную строку)
    bl _ft_strcpy                // Копируем строку в `dest`

    mov x0, x2                   // Возвращаем `dest`

    ldp x29, x30, [sp], #16
    ret

return_null:
    mov x0, #0                   // Возвращаем NULL
    ldp x29, x30, [sp], #16
    ret