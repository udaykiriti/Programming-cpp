; boot.asm - 512 bytes boot sector
[org 0x7C00]
bits 16

; read 1 sector (sector 2) into 0x1000
mov bx, 0x1000      ; ES:BX -> 0x0000:0x1000 (we'll assume DS=0x0000)
mov dh, 0
mov ch, 0
mov cl, 2           ; sector 2 (first sector = 1)
mov al, 1           ; read 1 sector
mov ah, 0x02
mov dl, [BOOT_DRIVE]
int 0x13

; jump to loaded kernel at 0x0000:0x1000
jmp 0x0000:0x1000

BOOT_DRIVE: db 0
times 510-($-$$) db 0
dw 0xAA55
