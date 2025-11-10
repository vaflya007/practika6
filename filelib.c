#include <fcntl.h>
#include <unistd.h>
#include "filelib.h"

void save_message(const char *filename, const char *message) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        return;
    }

    for (const char *p = message; *p; p++) {
        write(fd, p, 1);
    }

    close(fd);
}