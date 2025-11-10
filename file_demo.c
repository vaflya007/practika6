#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *filename = "myfile.txt";
    
    // 1. Создаём новый файл
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    
    // Проверяем на ошибку открытия
    if (fd == -1) {
        perror("Ошибка при создании файла");
        return 1;
    }
    
    // 2. Записываем строку в файл
    const char *text = "Hello, system programming!\n";
    ssize_t bytes_written = write(fd, text, strlen(text));
    
    if (bytes_written == -1) {
        perror("Ошибка при записи в файл");
        close(fd);
        return 1;
    }
    
    // 3. Закрываем файл
    if (close(fd) == -1) {
        perror("Ошибка при закрытии файла");
        return 1;
    }
    
    // 4. Выводим сообщение об успешной работе
    printf("Файл '%s' успешно создан и в него записаны данные\n", filename);
    
    return 0;
}
