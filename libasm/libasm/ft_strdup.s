;use malloc
BITS 64

SECTION .text
GLOBAL ft_strdup
extern malloc


; char *strdup(const char *s);
; rdi = s
ft_strdup:

    mov rsi, rdi     ; Load source pointer into RSI (source string)
    push rdi         ; Use for source string later on
    extern ft_strlen
    call ft_strlen

    inc rax         ; increment by one for 0 length string, this is for the nul terminator
    mov rdi, rax    ; place strlen result in first argument(rdi) for malloc
    push rax        ; used to set counter
    mov rax, 0
    call malloc wrt ..plt
    cmp rax, 0      ; verify if malloc returned NULL(0)
    je .end
    
    ; move from rsi to rdi
    mov rdi, rax    ; Load destination pointer into RDI (string destination)
    pop rcx
    pop rsi         ; Load s on stack into source string
    cld             ; Clear direction flag (increment mode)
    rep movsb       ; Copy ECX bytes from [RSI] to [RDI]
.end:
    ret