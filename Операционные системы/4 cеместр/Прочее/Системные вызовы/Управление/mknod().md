— создание специальных файлов

```
#include <sys/stat.h>
int mknod(const char *pathname, mode_t mode, dev_t dev);


```

Создает:

- Обычные файлы (S_IFREG)
    
- Каталоги (S_IFDIR)
    
- Специальные файлы устройств (S_IFCHR, S_IFBLK)
    
- FIFO (S_IFIFO)
    

**Создание FIFO (именованного канала):**

```

mknod("myfifo", S_IFIFO | 0666, 0);
```