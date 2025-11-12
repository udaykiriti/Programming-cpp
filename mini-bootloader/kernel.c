volatile char* vmem = (volatile char*)0xB8000;

void kernel_main() {
    const char* msg = "Hello qt from kernel!";
    for (int i = 0; msg[i] != 0; i++) {
        vmem[i*2] = msg[i];  
        vmem[i*2+1] = 0x0F;  
    }
    while (1); 
}
