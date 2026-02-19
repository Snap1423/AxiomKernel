void print(const char* str);
void clear_screen();
char get_char();

void kernel_main() {

    clear_screen();
    print("AxiomKernal v0.5\n");
    print("Type something:\n");

    while (1) {
        char c = get_char();

        if (c) {
            char str[2] = {c, '\0'};
            print(str);
        }
    }
}





