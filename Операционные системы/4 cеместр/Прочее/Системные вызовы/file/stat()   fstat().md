```
#include <sys/stat.h>

int stat(const char *pathname, struct stat *statbuf);
int fstat(int fd, struct stat *statbuf);
```

##  **получение информации о файле**

```
struct stat file_info;

// Для файла по имени
if (stat("file.txt", &file_info) == -1) {
    perror("stat failed");
    return;
}

// Для открытого файлового дескриптора
int fd = open("file.txt", O_RDONLY);
fstat(fd, &file_info);

printf("Размер: %ld байт\n", file_info.st_size);
printf("Inode: %ld\n", file_info.st_ino);
printf("Права: %o\n", file_info.st_mode & 0777);
printf("Владелец: %d\n", file_info.st_uid);
printf("Время изменения: %ld\n", file_info.st_mtime);

```