[org 0x7C00]
bits 16

; Load our 32-bit kernel from disk sector 2
mov ax, 0x07C0
mov ds, ax

mov bx, 0x1000      ; load kernel at 0x10000
mov ah, 0x02        ; BIOS read sectors
mov al, 1           ; read 1 sector
mov ch, 0           ; cylinder
mov dh, 0           ; head
mov cl, 2           ; sector number
mov dl, [BOOT_DRIVE]
int 0x13            ; read from disk into 0x1000

; jump to 32-bit kernel
jmp 0x0000:0x1000

BOOT_DRIVE: db 0
times 510 - ($ - $$) db 0
dw 0xAA55