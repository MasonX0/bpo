### **`` — управление файловым дескриптором

```
c

#include <fcntl.h>
int fcntl(int fd, int cmd, ... /* arg */ );


**Основные команды:**

c

// Получить/установить флаги
int flags = fcntl(fd, F_GETFL);
fcntl(fd, F_SETFL, flags | O_NONBLOCK);

// Установить блокировку файла
struct flock lock = {
    .l_type = F_WRLCK,
    .l_whence = SEEK_SET,
    .l_start = 0,
    .l_len = 0  // до EOF
};
fcntl(fd, F_SETLKW, &lock);  // Блокирующая блокировка
```