void print(const char* str);
void clear_screen();
void backspace();
char get_char();
void* kmalloc(unsigned int size);

int strcmp(const char* a, const char* b) {
    int i = 0;
    while (a[i] && b[i]) {
        if (a[i] != b[i]) return 0;
        i++;
    }
    return a[i] == b[i];
}

void print_int(int num) {
    char buffer[10];
    int i = 0;

    if (num == 0) {
        print("0");
        return;
    }

    while (num > 0) {
        buffer[i++] = (num % 10) + '0';
        num /= 10;
    }

    // reverse and print
    for (int j = i - 1; j >= 0; j--) {
        char c[2] = {buffer[j], '\0'};
        print(c);
    }
}


void kernel_main() {

    clear_screen();

    print("AxiomKernal v1.0\n");

    //  MEMORY VISUALIZATION
    print("\nMemory Visualization:\n");

    for (int i = 0; i < 10; i++) {
        kmalloc(4);
        print("[#]");
    }

    print("\n\n");

    //  SHELL STARTS HERE
    char buffer[128];
    int index = 0;

    while (1) {

        print("AxiomKernal > ");
        index = 0;

        while (1) {

            char c = get_char();

            if (c == '\n') {
                buffer[index] = '\0';
                break;
            }

            if (c == '\b') {
                if (index > 0) {
                    index--;
                    backspace();
                }
                continue;
            }

            if (c) {
                buffer[index++] = c;

                char str[2] = {c, '\0'};
                print(str);
            }
        }

        if (strcmp(buffer, "help")) {
            print("\nCommands: help clear about\n");
        }

        else if (strcmp(buffer, "clear")) {
            clear_screen();
        }

        else if (strcmp(buffer, "about")) {
            print("\nAxiomKernal - Simple OS Kernel Project\n");
        }

        else {
            print("\nUnknown command\n");
        }

        print("\n");
    }
}
