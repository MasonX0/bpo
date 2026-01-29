— неименованный канал

```
c

#include <unistd.h>
int pipe(int pipefd[2]);

Создает однонаправленный канал:

- `pipefd[0]` — для чтения
    
- `pipefd[1]` — для записи

```





пример:


```
int fd[2];
pipe(fd);  // Создаем канал

if (fork() == 0) {
    // Потомок пишет
    close(fd[0]);  // Закрываем чтение
    write(fd[1], "Hello", 6);
    exit(0);
} else {
    // Родитель читает
    close(fd[1]);  // Закрываем запись
    char buf[100];
    read(fd[0], buf, sizeof(buf));
    printf("Got: %s\n", buf);
}


```