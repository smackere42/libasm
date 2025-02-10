.section __TEXT, __text
.global _ft_read
.extern _errno

_ft_read:
    stp x29, x30, [sp, #-16]!   // Сохранение frame pointer и return address
    mov x29, sp                 // Обновляем frame pointer

    movz x16, #0x2000           // Загружаем младшую часть системного вызова
    movk x16, #0x0003, lsl #0   // Код `read` (0x200003)
    svc #0                      // Вызов системного сервиса

    cmp x0, #0                  // Проверяем, есть ли ошибка
    b.ge read_done              // Если `x0 >= 0`, всё ок, выходим

    neg x0, x0                  // Делаем x0 положительным (код ошибки)
    adrp x1, _errno@GOTPAGE      // Загружаем адрес `_errno`
    ldr  x1, [x1, _errno@GOTPAGEOFF] // Загружаем точный адрес `errno`
    str  w0, [x1]                 // Устанавливаем `errno`
    mov x0, #-1                   // Возвращаем -1 при ошибке

read_done:
    ldp x29, x30, [sp], #16      // Восстанавливаем frame pointer и return address
    ret