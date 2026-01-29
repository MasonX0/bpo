— создание жесткой ссылки

```

#include <unistd.h>
int link(const char *oldpath, const char *newpath);

Создает второе имя для того же файла (тот же inode).

```