void print(const char* str);
void clear_screen();
void backspace();
char get_char();

void kernel_main() {

    clear_screen();
    print("AxiomKernal v0.6\n");
    print("Type something:\n");

    while (1) {

        char c = get_char();

        if (c == '\b') {
            backspace();
        }
        else if (c) {
            char str[2] = {c, '\0'};
            print(str);
        }
    }
}





