BITS 64

SECTION .text
    GLOBAL ft_read
    extern __errno_location  ; Required to set errno in case of error

; ssize_t read(int fd(rdi), char *buf(rsi), size_t count(rdx))
ft_read:                  ; rdi = dest ; rsi = src
    mov rax, 0             ; read syscall number is 0
    syscall                ; all parameter to the read syscall are already in order
                           
                           ; syscall result is placed in rax
    cmp rax, 0              ; check result for success (0), if true return
    jge ft_read_end                
    
    ; setup errno value
    neg rax                 ; negate rax to get positive errno value
    mov rbx, rax            ; store errno in rbx
    call __errno_location wrt ..plt  ; get pointer to errno (pointer is into rax)
    mov [rax], ebx          ; store errno value inside errno ptr
    mov rax, -1             ; return -1 to indicate failure

ft_read_end:
    ret