#include <stddef.h>

static int cursor_position = 0;

void print(const char* str) {
    char* video_memory = (char*) 0xB8000;

    for (size_t i = 0; str[i] != '\0'; i++) {
        video_memory[cursor_position * 2] = str[i];
        video_memory[cursor_position * 2 + 1] = 0x07;
        cursor_position++;
    }
}
