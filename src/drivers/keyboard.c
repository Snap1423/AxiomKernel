unsigned char inb(unsigned short port) {
    unsigned char result;
    __asm__ volatile ("inb %1, %0" : "=a"(result) : "Nd"(port));
    return result;
}

char get_key() {
    unsigned char scancode;

    while (1) {
        if (inb(0x64) & 1) {   // Check if data available
            scancode = inb(0x60);
            return scancode;
        }
    }
}

