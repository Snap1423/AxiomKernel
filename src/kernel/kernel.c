void print(const char* str);
void clear_screen();
char get_key();

void kernel_main() {

    clear_screen();
    print("Press any key...\n");

    char key = get_key();

    print("Key detected!\n");

    while (1);
}




