###  **устаревший способ создания файла**

```

#include <fcntl.h>
int create(const char *pathname, mode_t mode);

**Эквивалентно:**

open(pathname, O_WRONLY | O_CREAT | O_TRUNC, mode);
```