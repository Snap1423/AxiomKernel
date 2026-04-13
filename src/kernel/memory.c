#include <stddef.h>

static unsigned int free_memory = 0x100000;

void* kmalloc(size_t size) {
    void* addr = (void*) free_memory;
    free_memory += size;
    return addr;
}
