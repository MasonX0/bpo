— изменение прав доступа

```
#include <sys/stat.h>
int chmod(const char *pathname, mode_t mode);
```

```
chmod("file.txt", 0644);  // rw-r--r--
chmod("script.sh", 0755); // rwxr-xr-x

```