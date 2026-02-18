void kernel_main() {

    char* video_memory = (char*) 0xB8000;

    const char* message = "AxiomKernal v0.1 - It Boots!";

    for (int i = 0; message[i] != '\0'; i++) {
        video_memory[i * 2] = message[i];      // character
        video_memory[i * 2 + 1] = 0x07;        // color (light grey on black)
    }

    while (1);
}

