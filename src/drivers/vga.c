#include <stddef.h>

#define VGA_WIDTH 80
#define VGA_HEIGHT 25

static int row = 0;
static int column = 0;

void print(const char* str) {
    char* video_memory = (char*) 0xB8000;

    for (size_t i = 0; str[i] != '\0'; i++) {

        if (str[i] == '\n') {
            column = 0;
            row++;
            continue;
        }

        int index = (row * VGA_WIDTH + column) * 2;

        video_memory[index] = str[i];
        video_memory[index + 1] = 0x07;

        column++;

        if (column >= VGA_WIDTH) {
            column = 0;
            row++;
        }
    }
}

