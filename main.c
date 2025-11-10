#include <stdio.h>
#include "filelib.h"

int main() {
    save_message("log.txt", "Start!\n");
    save_message("log.txt", "Processing...\n");
    save_message("log.txt", "Success!\n");

    printf("Сообщения записаны в log.txt\n");

    printf("Это обычный вывод (stdout)\n");
    fprintf(stderr, "Сообщение ошибки (stderr)\n");
    save_message("log.txt", "Запись в файл в библиотеке\n");
    return 0;
}
